/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c-ps_sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/23 20:45:11 by snemoto          ###   ########.fr       */
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

// static int	ps_check_max(t_list *lst, int max)
// {
// 	t_list	*cur;

// 	cur = lst->next;
// 	while (cur != lst)
// 	{
// 		if (max <= cur->val)
// 			max = cur->val;
// 		cur = cur->next;
// 	}
// 	return (max);
// }

// static int	ps_check_min(t_list *lst, int min)
// {
// 	t_list	*cur;

// 	cur = lst->next;
// 	while (cur != lst)
// 	{
// 		if (cur->val <= min)
// 			min = cur->val;
// 		cur = cur->next;
// 	}
// 	return (min);
// }

// void	ps_argc_six(t_list *a, t_list *b)
// {
// 	while (a->next->next->next != a->prev)
// 		ps_operations(a, b, "pb\n");
// 	ps_argc_three(a);
// 	ps_argc_three(b);
// 	while (!(ps_check_sort(a) && b->next == b))
// 	{
// 		if (ps_check_max(a, INT_MIN) > ps_check_min(b, INT_MAX) && b->next != b)
// 		{
// 			ps_operations(a, b, "rra\n");
// 			ps_operations(a, b, "pa\n");
// 		}
// 		else if (a->next->val > b->next->val && b->next != b)
// 			ps_operations(a, b, "pa\n");
// 		while (!ps_check_sort(a))
// 			ps_operations(a, b, "ra\n");			
// 	}
// }

// printf("	a[%d]\n", a->next->val);
// printf("	b[%d]\n", b->next->val);
