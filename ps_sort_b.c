/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 20:41:35 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_argc_two_b(t_list *b)
{
	t_list	*one;
	t_list	*two;

	one = b->next;
	two = b->next->next;
	if (one->val > two->val)
		ps_operations(b, b, "sb\n");
}

void	ps_argc_two_rev(t_list *b)
{
	t_list	*one;
	t_list	*two;

	one = b->next;
	two = b->next->next;
	if (one->val < two->val)
		ps_operations(b, b, "sb\n");
}

void	ps_argc_three_b(t_list *b)
{
	t_list	*one;
	t_list	*two;
	t_list	*thr;

	one = b->next;
	two = b->next->next;
	thr = b->prev;
	if (one->val > two->val && two->val < thr->val && one->val < thr->val)
		ps_operations(b, b, "sb\n");
	else if (one->val > two->val && two->val > thr->val && one->val > thr->val)
	{
		ps_operations(b, b, "sb\n");
		ps_operations(b, b, "rrb\n");
	}
	else if (one->val > two->val && two->val < thr->val && one->val > thr->val)
		ps_operations(b, b, "rb\n");
	else if (one->val < two->val && two->val > thr->val && one->val < thr->val)
	{
		ps_operations(b, b, "sb\n");
		ps_operations(b, b, "rb\n");
	}
	else if (one->val < two->val && two->val > thr->val && one->val > thr->val)
		ps_operations(b, b, "rrb\n");
}

void	ps_argc_three_rev(t_list *b)
{
	t_list	*one;
	t_list	*two;
	t_list	*thr;

	one = b->next;
	two = b->next->next;
	thr = b->prev;
	if (one->val < two->val && two->val > thr->val && one->val > thr->val)
		ps_operations(b, b, "sb\n");
	else if (one->val < two->val && two->val < thr->val && one->val < thr->val)
	{
		ps_operations(b, b, "sb\n");
		ps_operations(b, b, "rrb\n");
	}
	else if (one->val < two->val && two->val > thr->val && one->val < thr->val)
		ps_operations(b, b, "rb\n");
	else if (one->val > two->val && two->val < thr->val && one->val > thr->val)
	{
		ps_operations(b, b, "rrb\n");
		ps_operations(b, b, "sb\n");
	}
	else if (one->val > two->val && two->val < thr->val && one->val < thr->val)
		ps_operations(b, b, "rrb\n");
}
