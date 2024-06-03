/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:07:06 by paulo-do          #+#    #+#             */
/*   Updated: 2024/05/23 23:53:45 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_list	*ft_get_max(t_list **lst)
{
	t_list	*temp;
	int		target;

	target = ft_get_max_pos(lst);
	temp = (*lst);
	while (target != temp->index)
		temp = temp->next;
	return (temp);
}

void	ft_get_target(t_list *a, t_list *b)
{
	t_list		*temp_b;
	t_list		*target;
	long		best_match;

	while (a)
	{
		best_match = INT_MIN;
		temp_b = b;
		while (temp_b)
		{
			if (temp_b->content < a->content
				&& temp_b->content > best_match)
			{
				best_match = temp_b->content;
				target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (best_match == INT_MIN)
			a->target = ft_get_max(&b);
		else
			a->target = target;
		a = a->next;
	}
}

void	ft_get_cost(t_list *a, int len_a, int len_b)
{
	while (a)
	{
		if (a->median == a->target->median)
		{
			if (a->median == true)
			{
				if (a->index > a->target->index)
					a->cost = a->index;
				else
					a->cost = a->target->index;
			}
			else if ((len_a - a->index) > (len_b - a->target->index))
				a->cost = (len_a - a->index);
			else if ((len_a - a->index) < (len_b - a->target->index))
				a->cost = (len_b - a->target->index);
		}
		else
		{
			if (a->median)
				a->cost = a->index + len_b - a->target->index;
			else
				a->cost = len_a - a->index + a->target->index;
		}
		a = a->next;
	}
}
