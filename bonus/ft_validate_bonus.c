/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 04:03:11 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/15 04:03:30 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	error_center(int error)
{
	if (error == 1)
		write(2, "Error\n", 6);
	return (-1);
}

int	ft_check_dups(int c, char *argv[])
{
	int		i;
	long	temp;
	int		pos;

	i = 0;
	pos = 0;
	while (i < c)
	{
		temp = ft_atoi_long(argv[i]);
		if (temp >= -2147483648 && temp <= 2147483647)
		{
			while (pos < i)
			{
				if (temp == ft_atoi_long(argv[pos]))
					return (error_center(1));
				if (pos < i)
					pos++;
			}
			pos = 0;
		}
		else
			return (error_center(1));
		i++;
	}
	return (1);
}

int	ft_validate_args(int c, char *argv[])
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < c)
	{
		if (argv[j][0] == '\0')
			return (error_center(1));
		if ((argv[j][0] == '-' && argv[j][1] != '\0' ) ||
			(argv[j][0] == '+' && argv[j][1] != '\0'))
			i++;
		while (argv[j][i] != '\0')
		{
			if (ft_isdigit(argv[j][i]) == 0 || i >= 12)
				return (error_center(1));
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	ft_check_sort(int c, char *argv[])
{
	int	i;

	i = 0;
	while (i < c - 1)
	{
		if (ft_atoi_long(argv[i]) > ft_atoi_long(argv[i + 1]))
			return (-1);
		i++;
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