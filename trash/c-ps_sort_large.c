/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c-ps_sort_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/20 21:17:21 by snemoto          ###   ########.fr       */
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

static int	ps_check_max(t_list *a, int max)
{
	t_list	*cur;

	cur = a->next;
	while (cur != a)
	{
		if (max <= cur->val)
			max = cur->val;
		cur = cur->next;
	}
	return (max);
}

static char	*ps_find_num(t_list *a, int min, int max)
{
	t_list	*cur;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cur = a->next;
	while (cur != a)
	{
		if (cur->val == min || cur->val == max)
			break ;
		i++;
		cur = cur->next;
	}
	cur = a->prev;
	while (cur != a)
	{
		if (cur->val == min || cur->val == max)
			break ;
		j++;
		cur = cur->prev;
	}
	if (i > j)
		return ("rra\n");
	return ("ra\n");
}

void	ps_large_sort(t_list *a, t_list *b)
{
	int	min;
	int	max;
	int	cnt;

	cnt = 0;
	while (a->next != a)
	{
		min = ps_check_min(a, INT_MAX);
		max = ps_check_max(a, INT_MIN);
		if (a->next->val == min)
			ps_operations(a, b, "pb\n");
		else if (a->next->val == max)
		{
			cnt++;
			ps_operations(a, b, "pb\n");
			ps_operations(a, b, "rb\n");
		}
		ps_operations(a, b, ps_find_num(a, min, max));
	}
	while (b->next != b)
	{
		while (cnt-- > 0)
			ps_operations(a, b, "rrb\n");
		ps_operations(a, b, "pa\n");
	}
}

	// while (size-- > 0)
	// {
	// 	if (a->next->val > ave)
	// 		cnt++;
	// 		ps_operations(a, b, "ra\n");		
	// }
	// printf("%d\n", cnt);

// void	ps_large_sort(t_list *a, t_list *b)
// {
// 	size_t	size_a;
// 	size_t	size_b;
// 	size_t	ave;
// 	int		tmp;
// 	int		max;

// 	size_a = ps_lstsize(a);
// 	size_b = ps_lstsize(b);
// 	ave = (size_a + size_b) / 2;

// 	tmp = ave;
// 	while (tmp-- > 0)
// 		ps_operations(a, b, "pb\n");

// 	while (b->next != b)
// 	{
// 		if (a->prev->val > b->next->val)
// 		{
// 			max = a->prev->val;
// 			ps_operations(a, b, "rra\n");
// 		}
// 		else
// 		{
// 			max = b->next->val;
// 			ps_operations(a, b, "pa\n");			
// 		}
// 		while (max >= a->next->val)
// 		{
// 			if (a->prev->val > b->next->val)
// 				ps_operations(a, b, "rra\n");
// 			else
// 				ps_operations(a, b, "pa\n");
// 		}		
// 	}
// }

// void	ps_large_sort(t_list *a, t_list *b)
// {
// 	int min;
// 	int max;
// 	int ave;
// 	int cnt;
// 	int size;

// 	while (ps_lstsize(a) > 1)
// 	{
// 		min = ps_check_min(a, INT_MAX);
// 		max = ps_check_max(a, INT_MIN);
// 		ave = (min + max) / 2;
// 		cnt = 0;
// 		size = ps_lstsize(a);
// 		while (cnt < size / 2)
// 		{
// 			if (a->next->val > ave)
// 			{
// 				ps_operations(a, b, "pb\n");
// 				cnt++;
// 			}
// 			else
// 				ps_operations(a, b, "ra\n");			
// 		}
// 	}
// 	size = ps_lstsize(b);
// 	while (cnt < size / 2)
// 	{
// 		if (a->next->val > b->next->val)
// 			ps_operations(a, b, "pa\n");
// 		else if (a->prev->val < b->next->val)
// 		{
// 			ps_operations(a, b, "pa\n");
// 			ps_operations(a, b, "ra\n");			
// 		}
// 		else
// 			ps_operations(a, b, "rb\n");
// 		cnt++;
// 	}
// }

// t_list *cur = b;
// while (cur->next != b)
// {
// 	cur = cur->next;
// 	printf("%d ", cur->val);
// }

// static void	ps_push_a(t_list *a, t_list *b)
// {
// 	int	ave;
// 	int	size;

// 	ave = (ps_check_min(a, INT_MAX) + ps_check_max(a, INT_MIN)) / 2;
// 	size = ps_lstsize(a);
// 	while (ps_lstsize(a) != size / 2)
// 	{
// 		if (a->next->val > ave)
// 			ps_operations(a, b, "ra\n");
// 		else
// 			ps_operations(a, b, "pb\n");
// 	}	
// }

	else if (ft_strncmp(str, "rrr\n", ft_strlen("rrr\n")) == 0)
	{
		ps_rotate_reverse(a, b);
		ps_rotate_reverse(b, a);
	}
