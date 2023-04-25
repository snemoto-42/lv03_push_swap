/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/16 16:56:43 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_check_min(t_list *a, int min)
{
	t_list	*cur;

	cur = a->next;
	while (cur != a)
	{
		if (cur->val <= min)
			min = cur->val;
		cur = cur->next;
	}
	return (min);
}

static char	*ps_find_num(t_list *a, int num)
{
	t_list	*cur;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cur = a->next;
	while (cur != a)
	{
		if (cur->val == num)
			break ;
		i++;
		cur = cur->next;
	}
	cur = a->prev;
	while (cur != a)
	{
		if (cur->val == num)
			break ;
		j++;
		cur = cur->prev;
	}
	if (i > j)
		return ("rra\n");
	return ("ra\n");
}

void	ps_insertion_sort(t_list *a, t_list *b)
{
	int	min;

	while (a->next != a)
	{
		min = ps_check_min(a, INT_MAX);
		if (a->next->val == min)
			ps_operations(a, b, "pb\n");
		ps_operations(a, b, ps_find_num(a, min));
	}
	while (b->next != b)
		ps_operations(a, b, "pa\n");
}
