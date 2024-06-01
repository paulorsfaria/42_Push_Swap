/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:13:52 by paulo-do          #+#    #+#             */
/*   Updated: 2024/05/01 10:13:52 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_split_validate(t_list **a, char *argv[])
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(argv[0], ' ');
	while (split[i] != NULL)
		i++;
	if (ft_validate_args(i, split) == 1
		&& ft_check_dups(i, split) == 1
		&& ft_check_sort(i, split) == -1)
		ft_init_list(a, i, split);
	ft_free_split(split, i);
	return (1);
}
