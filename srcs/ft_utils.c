/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:09:49 by paulo-do          #+#    #+#             */
/*   Updated: 2024/05/21 12:07:45 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_update_index(t_list *lst)
{
	int	i;
	int	median;

	i = 0;
	if (!lst)
		return ;
	if (ft_listsize(lst) % 2 == 0)
		median = (ft_listsize(lst) / 2) - 1;
	else
		median = (ft_listsize(lst) / 2);
	while (lst)
	{
		lst->index = i;
		if (i <= median)
			lst->median = true;
		else
			lst->median = false;
		lst = lst->next;
		++i;
	}
}

int	ft_get_max_pos(t_list **a)
{
	t_list	*temp;
	int		max;
	int		index;

	temp = (*a);
	max = INT_MIN;
	while (temp)
	{
		if (max < temp->content)
		{
			max = temp->content;
			index = temp->index;
		}
		temp = temp->next;
	}
	return (index);
}

int	ft_get_min_pos(t_list **a)
{
	t_list	*temp;
	int		min;
	int		index;

	temp = (*a);
	min = INT_MAX;
	while (temp)
	{
		if (min > temp->content)
		{
			min = temp->content;
			index = temp->index;
		}
		temp = temp->next;
	}
	return (index);
}
