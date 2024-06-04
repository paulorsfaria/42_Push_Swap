/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:53:33 by paulo-do          #+#    #+#             */
/*   Updated: 2024/05/09 13:35:04 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/includes/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				cost;
	bool			median;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

// Validations
int		ft_split_validate(t_list **a, char *argv[]);
int		ft_check_sort(int c, char *argv[]);
int		ft_validate_args(int c, char *argv[]);
int		ft_check_dups(int c, char *argv[]);
int		ft_check_true_rev_sort(t_list **lst);
int		ft_check_true_sort(t_list **lst);

//Initialize list
void	ft_init_list(t_list **a, int size, char *argv[]);

//Movements
void	sa_sb(t_list **lst, char letter);
void	pa_pb(t_list **origin, t_list **dest, char letter);
void	ra_rb(t_list **lst, char letter);
void	rra_rrb(t_list **lst, char letter);
void	both(t_list **a, t_list **b, char letter);

// Utils
int		ft_get_min_pos(t_list **a);
int		ft_get_last(t_list **a);
int		error_center(int error);
int		ft_get_max_pos(t_list **a);
void	ft_update_index(t_list *lst);
int		ft_listsize(t_list *lst);
t_list	*ft_get_max(t_list **lst);

//sorting

void	ft_sort(t_list **a, t_list **b);
void	ft_get_target(t_list *a, t_list *b);
void	ft_get_cost(t_list *a, int len_a, int len_b);
int		ft_find_cheapest(t_list *a);
void	ft_prepare_for_push(t_list **a, t_list **b);
void	finish_sort(t_list **a, t_list **b);
#endif
