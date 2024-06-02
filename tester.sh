#!/bin/bash
# make and clear or create file results
make > /dev/null
> results

# check if there is an arg $1 for the quantity if not set quantity as 5
if [ -z "$1" ]
  then
    quantity=5
  else
    quantity=$1
fi

# check if there is a second arg $2 for the number of tests if not set quantity as 100
if [ -z "$2" ]
  then
    tests=100
  else
    tests=$2
fi

# Function to generate a random number between -50 and 50
generate_random_number() {
      echo $(( RANDOM % 10000 - 5000 ))
}

# Function to generate a unique set of defined numbers
generate_unique_set() {
    numbers=()
    while (( ${#numbers[@]} < quantity)); do
        num=$(generate_random_number)
        if ! contains "$num" "${numbers[@]}"; then
            numbers+=("$num")
        fi
    done
    echo "${numbers[@]}"
}

# Function to check if a number is already in the array
contains() {
    local e
    for e in "${@:2}"; do [[ $e == $1 ]] && return 0; done
    return 1
}

# Main script
echo "Testing $2 unique sets of numbers:"
failed_tests=(0)
median_moves=(0)
for ((i=1; i<=tests; i++)); do
    set_str=$(generate_unique_set)
       # echo "testing with $set_str\n";
    output=$(./push_swap $set_str | ./checker_linux $set_str)
    moves=$(./push_swap $set_str > moves && cat moves | wc -w)
    total_moves=$((total_moves + moves))

   # Check if the moves meet the criteria based on quantity
    case $quantity in
        5)
            max_moves=12
            ;;
        100)
            max_moves=700
            ;;
        500)
            max_moves=5500
            ;;
        *)
            max_moves=10000 # Default value for other quantities, adjust as necessary
            ;;
    esac

    if [ $moves -le $max_moves ]; then
        if echo "$output" | grep -q "OK"; then
            echo -e "\e[32mTest $i passed with $moves moves\e[0m" && echo -e "Test $i passed with $moves moves and numbers: $set_str" >> results
        else
            ((failed_tests++))
            echo -e "\e[31mTest $i failed:\e[0m push_swap $set_str" && echo "Test $i failed with $moves moves: push_swap $set_str" >> results
        fi
    else
        ((failed_tests++))
        echo -e "\e[31mTest $i failed due to excessive moves ($moves > $max_moves)\e[0m" && echo "Test $i failed due to excessive moves ($moves > $max_moves): push_swap $set_str" >> results
    fi
done

    average_moves=$(echo "scale=2; $total_moves / $tests" | bc)
    echo "Total moves: $total_moves Average moves: $average_moves"
    echo "Number of failed tests: $failed_tests" | tee -a results
# removes file moves after the last test
rm moves
