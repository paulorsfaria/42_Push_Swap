/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:43:11 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/17 19:44:27 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

int	do_moves(t_list **a, t_list **b, char *str)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa_sb(a);
	else if (!ft_strncmp(str, "sb\n", 3))
		sa_sb(b);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa_pb(b, a);
	else if (!ft_strncmp(str, "pb\n", 3))
		pa_pb(a, b);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra_rb(a);
	else if (!ft_strncmp(str, "rb\n", 3))
		ra_rb(b);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra_rrb(a);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rra_rrb(b);
	else if (!ft_strncmp(str, "ss\n", 3))
		both(a, b, 's');
	else if (!ft_strncmp(str, "rr\n", 3))
		both(a, b, 'r');
	else if (!ft_strncmp(str, "rrr\n", 4))
		both(a, b, 'u');
	else
		return (-1);
	return (1);
}

int	ft_listsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_get_inputs(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (do_moves(a, b, line) == -1)
		{
			write(2, "Error\n", 6);
			ft_free_stack(a);
			ft_free_stack(b);
			free(line);
			exit(-1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ft_check_true_sort(a) == 1 && ft_listsize(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
			&& ft_check_dups(argc, argv + 1) == 1)
			ft_init_list(&a, argc, argv + 1);
	if (a)
	{
		ft_get_inputs(&a, &b);
		ft_free_stack(&a);
		ft_free_stack(&b);
	}
	return (0);
}
