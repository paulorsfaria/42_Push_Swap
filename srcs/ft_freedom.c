/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:52:51 by paulo-do          #+#    #+#             */
/*   Updated: 2024/04/30 14:52:54 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_split(char **s, int i)
{
	while (i > 0)
	{
		i--;
		free(s[i]);
	}
	free(s);
}

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
