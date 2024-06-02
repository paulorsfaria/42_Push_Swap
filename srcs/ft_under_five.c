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

int	ft_check_true_rev_sort(t_list **lst)
{
	t_list	*temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return (1);
	temp = *lst;
	while (temp->next != NULL)
	{
		if (temp->content < temp->next->content)
			return (-1);
		temp = temp->next;
	}
	return (1);
}

int	ft_get_last(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	return (temp->content);
}

void	finish_rev_sort(t_list **b)
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

void	ft_over_five(t_list **a, t_list **b, int flag)
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
