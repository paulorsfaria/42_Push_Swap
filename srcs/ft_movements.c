/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:52:39 by paulo-do          #+#    #+#             */
/*   Updated: 2024/05/27 17:08:13 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa_sb(t_list **lst, char letter)
{
	int	temp;

	if (!lst || !*lst || !(*lst)->next || !letter)
		return ;
	temp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = temp;
	if (letter == 'a' || letter == 'b')
		ft_printf("s%c\n", letter);
}

void	both(t_list **a, t_list **b, char letter)
{
	if (!a || !*b || !letter)
		return ;
	if (letter == 's')
	{
		sa_sb(a, 'n');
		sa_sb(b, 'n');
		ft_printf("ss\n");
	}
	else if (letter == 'r')
	{
		ra_rb(a, 'n');
		ra_rb(b, 'n');
		ft_printf("rr\n");
	}
	else if (letter == 'u')
	{
		rra_rrb(a, 'n');
		rra_rrb(b, 'n');
		ft_printf("rrr\n");
	}
}

void	pa_pb(t_list **origin, t_list **dest, char letter)
{
	t_list	*temp;

	if (!origin || !*origin || !dest || !letter)
		return ;
	temp = *origin;
	(*origin) = (*origin)->next;
	temp->next = *dest;
	(*dest) = temp;
	if (letter == 'a' || letter == 'b')
		ft_printf("p%c\n", letter);
}

void	ra_rb(t_list **lst, char letter)
{
	t_list	*temp;

	if (!lst || !*lst || !letter)
		return ;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *lst;
	*lst = (*lst)->next;
	temp->next->next = NULL;
	if (letter == 'a' || letter == 'b')
		ft_printf("r%c\n", letter);
}

void	rra_rrb(t_list **lst, char letter)
{
	t_list	*last_node;

	if (!lst || !*lst || !(*lst)->next ||!letter)
		return ;
	last_node = *lst;
	while (last_node->next->next != NULL)
		last_node = last_node->next;
	last_node->next->next = *lst;
	*lst = last_node->next;
	last_node->next = NULL;
	if (letter == 'a' || letter == 'b')
		ft_printf("rr%c\n", letter);
}
