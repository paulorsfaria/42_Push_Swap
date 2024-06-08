/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:53:02 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/02 10:05:59 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_list **a)
{
	t_list	*temp;

	while ((*a))
	{
		temp = (*a);
		(*a) = (*a)->next;
		free(temp);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	argc--;
	if (argc == 0)
		return (1);
	else if (argc == 1)
		ft_split_validate(&a, argv + 1);
	else if (argc > 1)
		if (ft_validate_args(argc, argv + 1) == 1
			&& ft_check_dups(argc, argv + 1) == 1
			&& ft_check_sort(argc, argv + 1) == -1)
			ft_init_list(&a, argc, argv + 1);
	if (a)
	{
		ft_update_index(a);
		ft_sort(&a, &b);
		ft_free_stack(&a);
	}
	return (0);
}
