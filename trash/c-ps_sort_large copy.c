/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/21 18:55:56 by snemoto          ###   ########.fr       */
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

// static int	ps_check_max(t_list *a, int max)
// {
// 	t_list	*cur;

// 	cur = a->next;
// 	while (cur != a)
// 	{
// 		if (max <= cur->val)
// 			max = cur->val;
// 		cur = cur->next;
// 	}
// 	return (max);	
// }

void	ps_insertion_sort(t_list *a, t_list *b)
{
	int		min;
	// int		max;

	while (a->next != a)
	{
		min = ps_check_min(a, INT_MAX);
		// max = ps_check_max(a, INT_MIN);
		// if (a->next->val == max)
			// ps_operations(a, b, "pb\nrrb\n");
		if (a->next->val == min)
			ps_operations(a, b, "pb\n");
		ps_operations(a, b, "ra\n");
	}
	while (b->next != b)
		ps_operations(a, b, "pa\n");
}
