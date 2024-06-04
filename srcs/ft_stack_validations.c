/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_validations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:00:08 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/04 11:00:08 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	ft_check_true_sort(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			return (-1);
		temp = temp->next;
	}
	return (1);
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

int	ft_get_last(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	return (temp->content);
}
