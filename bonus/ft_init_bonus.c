/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 04:03:26 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/15 04:03:26 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../includes/push_swap_bonus.h"

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