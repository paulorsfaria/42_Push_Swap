/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:53:24 by paulo-do          #+#    #+#             */
/*   Updated: 2024/05/03 05:54:01 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_list(t_list **a, int size, char *argv[])
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return ;
	*a = temp;
	while (i < size)
	{
		temp->content = ft_atoi(argv[i]);
		temp->index = i + 1;
		temp->target = NULL;
		temp->cost = 0;
		if (i + 1 < size)
		{
			temp->next = (t_list *)malloc(sizeof(t_list));
			temp = temp->next;
		}
		else
			temp->next = NULL;
		i++;
	}
	temp->next = NULL;
}
