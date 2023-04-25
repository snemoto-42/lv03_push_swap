/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/21 17:06:41 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_six_op(t_list *a, t_list *b)
{
	int	flag_min_b;

	while (b->next != b)
	{
		flag_min_b = 0;
		if (ps_check_min(a, INT_MAX) > b->next->val)
			flag_min_b = 1;
		if (flag_min_b && ps_check_sort(a))
			ps_operations(a, b, "pa\n");
		else if (a->prev->val < b->next->val)
			ps_operations(a, b, "pa\n");
		else
			ps_operations(a, b, "rra\n");
	}
	while (!ps_check_sort(a))
		ps_operations(a, b, "rra\n");
}

static void	ps_six(t_list *a, t_list *b)
{
	if (a->next->val > b->next->val)
		while (b->next != b)
			ps_operations(a, b, "pa\n");
	else if (a->prev->val < b->prev->val)
	{
		while (b->next != b)
			ps_operations(a, b, "pa\n");
		while (!ps_check_sort(a))
			ps_operations(a, b, "rra\n");
	}
	else
		ps_six_op(a, b);
}

void	ps_argc_six(t_list *a, t_list *b, int arg)
{
	while (a->next->next->next != a->prev)
		ps_operations(a, b, "pb\n");
	ps_argc_three(a);
	if (arg == 5)
		ps_argc_two_rev(b);
	else if (arg == 6)
		ps_argc_three_rev(b);
	ps_six(a, b);
}
