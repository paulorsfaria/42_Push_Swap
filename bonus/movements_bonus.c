/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:23:16 by paulo-do          #+#    #+#             */
/*   Updated: 2024/06/14 23:23:16 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sa_sb(t_list **lst)
{
	int	temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = temp;
}

void	pa_pb(t_list **origin, t_list **dest)
{
	t_list	*temp;

	if (!origin || !*origin || !dest)
		return ;
	temp = *origin;
	(*origin) = (*origin)->next;
	temp->next = *dest;
	(*dest) = temp;

}

void	ra_rb(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *lst;
	*lst = (*lst)->next;
	temp->next->next = NULL;
}

void	rra_rrb(t_list **lst)
{
	t_list	*last_node;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	last_node = *lst;
	while (last_node->next->next != NULL)
		last_node = last_node->next;
	last_node->next->next = *lst;
	*lst = last_node->next;
	last_node->next = NULL;
}

void	both(t_list **a, t_list **b, char letter)
{
	if (!a || !*b || !letter)
		return ;
	if (letter == 's')
	{
		sa_sb(a);
		sa_sb(b);
	}
	else if (letter == 'r')
	{
		ra_rb(a);
		ra_rb(b);
	}
	else if (letter == 'u')
	{
		rra_rrb(a);
		rra_rrb(b);
	}
}