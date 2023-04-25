/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 21:07:44 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ps_push_b(t_list *a, t_list *b, int size, size_t cnt)
{
	int		ave;
	int		odd;

	odd = 0;
	ave = (ps_check_min(b, INT_MAX) + ps_check_max(b, INT_MIN)) / 2;
	if (size % 2 == 1)
		odd = 1;
	while (ps_lstsize(b) != size / 2 + odd)
	{
		if (b->next->val < ave + 1)
			ps_operations(a, b, "rb\n");
		else
		{
			ps_operations(a, b, "pa\n");
			cnt++;
		}
	}
	return (cnt);
}

static void	ps_sub_sort(t_list *a, t_list *b)
{
	t_list	*cur;

	if (ps_lstsize(b) == 3)
		ps_argc_three_b(b);
	else
		ps_argc_two_b(b);
	cur = b;
	while (cur->next != b)
	{
		ps_operations(a, b, "pa\n");
		ps_operations(a, b, "ra\n");
	}
}

static t_list	*ps_large(t_list *a, t_list *b, int size, size_t idx)
{
	size_t	i;
	size_t	*cnt;

	cnt = (size_t *) malloc(sizeof(size_t) * size);
	if (cnt == NULL)
		return (NULL);
	while (size > 3)
	{
		size = ps_lstsize(b);
		cnt[idx] = ps_push_b(a, b, size, 0);
		idx++;
	}
	ps_sub_sort(a, b);
	while (idx-- > 0)
	{
		i = 0;
		while (i++ < cnt[idx])
			ps_operations(a, b, "pb\n");
		if (cnt[idx] > 3)
			ps_large(a, b, ps_lstsize(b), 0);
		ps_sub_sort(a, b);
	}
	free(cnt);
	return (a);
}

t_list	*ps_large_sort(t_list *a, t_list *b, int size)
{
	int	odd;
	int	ave;

	odd = 0;
	if (size % 2 == 1)
		odd = 1;
	ave = (ps_check_min(a, INT_MAX) + ps_check_max(a, INT_MIN)) / 2;
	while (ps_lstsize(b) != size / 2 + odd)
	{
		if (a->next->val < ave + 1)
			ps_operations(a, b, "pb\n");
		else
			ps_operations(a, b, "ra\n");
	}
	if (ps_large(a, b, size, 0) == NULL)
		return (NULL);
	while (ps_lstsize(a) != size / 2 + odd)
		ps_operations(a, b, "pb\n");
	if (ps_large(a, b, size, 0) == NULL)
		return (NULL);
	return (a);
}
