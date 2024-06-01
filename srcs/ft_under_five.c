/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_under_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 23:41:50 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/01 05:38:21 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	if_three(t_list **a)
{
	if (ft_check_true_sort(a) != 0)
	{
		if (ft_get_max_pos(a) == 0)
		{
			ra_rb(a, 'a');
			if (ft_check_true_sort(a) != 1)
				sa_sb(a, 'a');
		}
		else if (ft_get_max_pos(a) == 1)
		{
			if (ft_get_min_pos(a) == 2)
				rra_rrb(a, 'a');
			if (ft_get_min_pos(a) == 0)
			{
				sa_sb(a, 'a');
				ra_rb(a, 'a');
			}
		}
		else if (ft_get_max_pos(a) == 2)
			sa_sb(a, 'a');
	}
}

void	if_four(t_list **a, t_list **b)
{
	if (ft_get_min_pos(a) == 1)
		sa_sb(a, 'a');
	else if (ft_get_min_pos(a) == 2)
	{
		if (ft_get_max_pos(a) == 0)
			sa_sb(a, 'a');
		rra_rrb(a, 'a');
		rra_rrb(a, 'a');
	}
	else if (ft_get_min_pos(a) == 3)
		rra_rrb(a, 'a');
	if (ft_check_true_sort(a) == 1)
		return ;
	pa_pb(a, b, 'b');
	ft_update_index(*a);
	if_three(a);
	pa_pb(b, a, 'a');
}

void	if_five(t_list **a, t_list **b)
{
	if (ft_get_min_pos(a) == 1)
		sa_sb(a, 'a');
	else if (ft_get_min_pos(a) == 2)
	{
		ra_rb(a, 'a');
		ra_rb(a, 'a');
	}
	else if (ft_get_min_pos(a) == 3)
	{
		rra_rrb(a, 'a');
		rra_rrb(a, 'a');
	}
	else if (ft_get_min_pos(a) == 4)
		rra_rrb(a, 'a');
	if (ft_check_true_sort(a) == 1)
		return ;
	pa_pb(a, b, 'b');
	ft_update_index(*a);
	if_four(a, b);
	pa_pb(b, a, 'a');
}

int	ft_find_cheapest(t_list *a)
{
	t_list	*temp;
	int		cost;
	int		index;

	index = 0;
	temp = a;
	cost = INT_MAX;
	while (temp)
	{
		if (cost > temp->cost)
		{
			cost = temp->cost;
			index = temp->index;
			if (cost == 0)
				return (index);
		}
		temp = temp->next;
	}
	return (index);
}

void	ft_both_equal(t_list **a, t_list **b, int goal, bool flag)
{
	t_list	*temp_a;

	temp_a = *a;
	while (temp_a->index != goal)
		temp_a = temp_a->next;
	if (flag == true)
	{
		while ((*a)->index != goal && temp_a->target->index != (*b)->index)
			both(a, b, 'r');
		if ((*a)->index != goal || (*b)->index != (*a)->target->index)
		{
			while ((*a)->index != goal)
				ra_rb(a, 'a');
			while ((*b)->index != (*a)->target->index)
				ra_rb(b, 'b');
		}
	}
	else if (flag == false)
	{
		while ((*a)->index != goal && temp_a->target->index != (*b)->index)
			both(a, b, 'u');
		if ((*a)->index != goal || (*b)->index != (*a)->target->index)
		{
			while ((*a)->index != goal)
				rra_rrb(a, 'a');
			while ((*b)->index != (*a)->target->index)
				rra_rrb(b, 'b');
		}
	}
	pa_pb(a, b, 'b');
}

void	ft_if_dif(t_list **a, t_list **b, int goal, bool flag)
{
	if (flag == true)
	{
		while ((*a)->index != goal)
			ra_rb(a, 'a');
		while ((*a)->target->content != (*b)->content)
			rra_rrb(b, 'b');
	}
	else if (flag == false)
	{
		while ((*a)->index != goal)
			rra_rrb(a, 'a');
		while ((*a)->target->content != (*b)->content)
			ra_rb(b, 'b');
	}
	pa_pb(a, b, 'b');

}

void	ft_prepare_for_push(t_list **a, t_list **b)
{
	int		goal;
	t_list	*temp;

	if (!*a || !*b)
		return ;
	temp = *a;
	ft_update_index(*a);
	ft_update_index(*b);
	ft_get_target(*a, *b);
	ft_get_cost(*a, ft_listsize(*b));
	goal = ft_find_cheapest(*a);
	while (temp->index != goal)
		temp = temp->next;
	if (temp->median == temp->target->median)
		ft_both_equal(a, b, goal, temp->median);
	else
		ft_if_dif(a, b, goal, temp->median);
}

int	ft_check_true_rev_sort(t_list **lst)
{
	t_list	*temp;

	temp = (*lst);
	while (temp->next->next != NULL)
	{
		if (temp->content < temp->next->content)
			return (-1);
		temp = temp->next;
	}
	if (temp->content < temp->next->content)
		return (-1);
	return (1);
}
int ft_get_last(t_list **a)
{
	t_list *temp;
	temp = *a;
	while (temp->next)
		temp=temp->next;
	return (temp->content);

}

void	ft_over_five(t_list **a, t_list **b, int flag)
{
	int last_nbr;
	last_nbr = INT_MIN;

	if (flag == 1)
	{
		pa_pb(a, b, 'b');
		pa_pb(a, b, 'b');
	}
	ft_prepare_for_push(a, b);
	if (ft_listsize(*a) > 5)
		ft_over_five(a, b, 0);
	else{
		ft_update_index(*a);
		if_five(a, b);
		ft_update_index(*b);
		if (ft_get_max_pos(b) <= ft_listsize(*b) / 2)
			while (ft_check_true_rev_sort(b) != 1)
				ra_rb(b, 'b');
		else
			while (ft_check_true_rev_sort(b) != 1)
				rra_rrb(b, 'b');
		//printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	//	print_list(*a);
		while (*b)
		{
			last_nbr= ft_get_last(a);
			while (last_nbr < (*a)->content && last_nbr > (*b)->content)
			{
				//printf("%d < %d && %d > %d \n", last_nbr , (*a)->content , last_nbr, (*b)->content);
				rra_rrb(a, 'a');
				last_nbr = ft_get_last(a);
			}
		//	printf("%d < %d && %d > %d \n", last_nbr , (*a)->content , last_nbr, (*b)->content);
			pa_pb(b, a, 'a');
		}
		while(ft_check_true_sort(a) == -1)
			rra_rrb(a, 'a');//got infinite loops
	}
}


// #TODO make it so when adding to b to a i will check if the last number on a is between first of a and first of b;