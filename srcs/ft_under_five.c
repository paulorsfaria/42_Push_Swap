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

static void	if_three(t_list **a)
{
	if (ft_check_true_sort(a) != 1)
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

static void	if_four(t_list **a, t_list **b)
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

static void	if_five(t_list **a, t_list **b)
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

static void	ft_over_five(t_list **a, t_list **b, int flag)
{
	if (flag == 1)
	{
		pa_pb(a, b, 'b');
		pa_pb(a, b, 'b');
	}
	ft_prepare_for_push(a, b);
	if (ft_listsize(*a) > 5)
		ft_over_five(a, b, 0);
	else
	{
		finish_sort(a, b);
		while (ft_check_true_sort(a) == -1)
			rra_rrb(a, 'a');
	}
}

void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	ft_update_index(*a);
	size = ft_listsize(*a);
	if (size == 2)
		sa_sb(a, 'a');
	else if (size == 3)
		if_three(a);
	else if (size == 4)
		if_four(a, b);
	else if (size == 5)
		if_five(a, b);
	else
		ft_over_five(a, b, 1);
}
