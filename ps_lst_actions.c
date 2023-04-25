/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 17:07:24 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_lst_add_front(t_list *lst, t_list *new)
{
	t_list	*front;

	if (new == NULL)
		return (NULL);
	front = lst->next;
	new->prev = lst;
	new->next = front;
	lst->next = new;
	front->prev = new;
	return (lst);
}

t_list	*ps_lst_add_last(t_list *lst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return (NULL);
	last = lst->prev;
	new->prev = last;
	new->next = lst;
	last->next = new;
	lst->prev = new;
	return (lst);
}

t_list	*ps_lst_remove_front(t_list *lst)
{
	t_list	*front;

	if (lst->next == lst)
		return (lst);
	front = lst->next;
	lst->next = front->next;
	front->next->prev = lst;
	front->next = front;
	front->prev = front;
	return (front);
}

t_list	*ps_lst_remove_last(t_list *lst)
{
	t_list	*last;

	if (lst->prev == lst)
		return (lst);
	last = lst->prev;
	lst->prev = last->prev;
	last->prev->next = lst;
	last->next = last;
	last->prev = last;
	return (last);
}
