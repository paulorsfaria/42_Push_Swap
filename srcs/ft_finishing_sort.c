/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finishing_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:10:18 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/04 13:41:01 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	finish_rev_sort(t_list **b)
{
	ft_update_index(*b);
	if (ft_get_max_pos(b) <= ft_listsize(*b) / 2)
		while (ft_check_true_rev_sort(b) != 1)
			ra_rb(b, 'b');
	else
		while (ft_check_true_rev_sort(b) != 1)
			rra_rrb(b, 'b');
}

void	finish_sort(t_list **a, t_list **b)
{
	ft_sort(a, b);
	finish_rev_sort(b);
	if (ft_get_last(a) > (*b)->content)
	{
		rra_rrb(a, 'a');
		pa_pb(a, b, 'b');
	}
	while (*b)
	{
		while (ft_get_last(a) < (*a)->content
			&& ft_get_last(a) > (*b)->content)
			rra_rrb(a, 'a');
		pa_pb(b, a, 'a');
	}
}

static void	ft_both_equal(t_list **a, t_list **b, int goal, bool flag)
{
	if (flag == true)
	{
		if ((*a)->index != goal)
			while ((*a)->index != goal)
				ra_rb(a, 'a');
		if ((*b)->index != (*a)->target->index)
			while ((*b)->index != (*a)->target->index)
				ra_rb(b, 'b');
	}
	else if (flag == false)
	{
		if ((*a)->index != goal)
			while ((*a)->index != goal)
				rra_rrb(a, 'a');
		if ((*b)->index != (*a)->target->index)
			while ((*b)->index != (*a)->target->index)
				rra_rrb(b, 'b');
	}
	pa_pb(a, b, 'b');
}

static void	ft_if_dif(t_list **a, t_list **b, int goal, bool flag)
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
	ft_get_cost(*a, ft_listsize(*a), ft_listsize(*b));
	goal = ft_find_cheapest(*a);
	while (temp->index != goal)
		temp = temp->next;
	if (temp->median == temp->target->median)
	{
		if (temp->median == true)
			while ((*a)->index != goal && temp->target->index != (*b)->index)
				both(a, b, 'r');
		else
			while ((*a)->index != goal && temp->target->index != (*b)->index)
				both(a, b, 'u');
		ft_both_equal(a, b, goal, temp->median);
	}
	else
		ft_if_dif(a, b, goal, temp->median);
}
