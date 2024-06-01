/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:53:15 by paulo-do          #+#    #+#             */
/*   Updated: 2024/05/09 10:52:20 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	error_center(int error)
{
	if (error == 1 || error == 2)
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
		if (temp > -2147483648 && temp < 2147483647)
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
				return (error_center(2));
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
