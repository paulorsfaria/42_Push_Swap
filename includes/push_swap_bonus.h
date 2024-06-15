/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:53:33 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/15 04:05:14 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libraries/libft/includes/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

// Validations
int		ft_split_validate(t_list **a, char *argv[]);
int		ft_check_sort(int c, char *argv[]);
int		ft_validate_args(int c, char *argv[]);
int		ft_check_dups(int c, char *argv[]);
int		ft_check_true_sort(t_list **lst);
int	error_center(int error);

//Initialize list
void	ft_init_list(t_list **a, int size, char *argv[]);

//Movements
void	sa_sb(t_list **lst);
void	pa_pb(t_list **origin, t_list **dest);
void	ra_rb(t_list **lst);
void	rra_rrb(t_list **lst);
void	both(t_list **a, t_list **b, char letter);

#endif
