/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/20 19:50:27 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_argc_two(t_list *a)
{
	t_list	*one;
	t_list	*two;

	one = a->next;
	two = a->next->next;
	if (one->val > two->val)
		ps_operations(a, a, "sa\n");
}

void	ps_argc_three(t_list *a)
{
	t_list	*one;
	t_list	*two;
	t_list	*thr;

	one = a->next;
	two = a->next->next;
	thr = a->prev;
	if (one->val > two->val && two->val < thr->val && one->val < thr->val)
		ps_operations(a, a, "sa\n");
	else if (one->val > two->val && two->val > thr->val && one->val > thr->val)
	{
		ps_operations(a, a, "sa\n");
		ps_operations(a, a, "rra\n");
	}
	else if (one->val > two->val && two->val < thr->val && one->val > thr->val)
		ps_operations(a, a, "ra\n");
	else if (one->val < two->val && two->val > thr->val && one->val < thr->val)
	{
		ps_operations(a, a, "sa\n");
		ps_operations(a, a, "ra\n");
	}
	else if (one->val < two->val && two->val > thr->val && one->val > thr->val)
		ps_operations(a, a, "rra\n");
}
