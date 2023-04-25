/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:44:04 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 20:36:31 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_list *lst)
{
	int	tmp;

	tmp = lst->val;
	lst->val = lst->next->val;
	lst->next->val = tmp;
}

void	ps_rotate(t_list *lst)
{
	t_list	*front;

	front = ps_lst_remove_front(lst);
	if (front != lst)
		ps_lst_add_last(lst, front);
}

void	ps_rotate_reverse(t_list *lst)
{
	t_list	*last;

	last = ps_lst_remove_last(lst);
	if (last != lst)
		ps_lst_add_front(lst, last);
}

void	ps_push(t_list *lst1, t_list *lst2)
{
	t_list	*tmp;

	tmp = ps_lst_remove_front(lst1);
	if (tmp != lst1)
		ps_lst_add_front(lst2, tmp);
}

void	ps_operations(t_list *a, t_list *b, char *str)
{
	if (ft_strncmp(str, "sa\n", ft_strlen("sa\n")) == 0)
		ps_swap(a->next);
	else if (ft_strncmp(str, "sb\n", ft_strlen("sb\n")) == 0)
		ps_swap(b->next);
	else if (ft_strncmp(str, "ra\n", ft_strlen("ra\n")) == 0)
		ps_rotate(a);
	else if (ft_strncmp(str, "rb\n", ft_strlen("rb\n")) == 0)
		ps_rotate(b);
	else if (ft_strncmp(str, "rra\n", ft_strlen("rra\n")) == 0)
		ps_rotate_reverse(a);
	else if (ft_strncmp(str, "rrb\n", ft_strlen("rrb\n")) == 0)
		ps_rotate_reverse(b);
	else if (ft_strncmp(str, "pb\n", ft_strlen("pb\n")) == 0)
		ps_push(a, b);
	else if (ft_strncmp(str, "pa\n", ft_strlen("pa\n")) == 0)
		ps_push(b, a);
	write(STDOUT_FILENO, str, ft_strlen(str));
}
