/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c-min-ps_sort_large.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/23 18:56:07 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	ps_check_ave(t_list *lst, int min, int max)
// {
// 	int		ave;	
// 	t_list	*cur;

// 	cur = lst->next;
// 	while (cur != lst)
// 	{
// 		if (!(cur->val == min && cur->val == max))
// 		{
// 			ave = cur->val;
// 			break ;
// 		}
// 		cur = cur->next;
// 	}
// 	return (ave);
// }

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

static int	ps_check_min(t_list *lst, int min)
{
	t_list	*cur;

	cur = lst->next;
	while (cur != lst)
	{
		if (cur->val <= min)
			min = cur->val;
		cur = cur->next;
	}
	return (min);
}

static void	ps_ps(t_list *a, t_list *b)
{
	if (a->next->val > a->next->next->val \
		&& a->next->val < a->next->next->next->val)
		ps_operations(a, b, "sa\n");
	else if (a->next->val > a->prev->val)
		ps_operations(a, b, "ra\n");
	else if (a->next->val > a->next->next->val)
	{
		while (a->next->val < a->prev->val)
		{
			ps_operations(a, b, "rra\n");
			ps_operations(a, b, "sa\n");
		}
		while (a->next->val > a->prev->val)
			ps_operations(a, b, "ra\n");
	}
}

void	ps_argc_six(t_list *a, t_list *b)
{
	int	num;

	while (a->next->next->next != a->prev)
		ps_operations(a, b, "pb\n");
	ps_argc_three(a);

	num = ps_check_min(b, INT_MAX);
	while (b->next->val != num)
		ps_operations(a, b, "rb\n");
	ps_operations(a, b, "pa\n");
	ps_ps(a, b);

	num = ps_check_min(b, INT_MAX);
	while (b->next->val != num)
		ps_operations(a, b, "rb\n");
	ps_operations(a, b, "pa\n");
	ps_ps(a, b);

	ps_operations(a, b, "pa\n");
	ps_ps(a, b);
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
