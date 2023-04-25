/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_rank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 20:51:22 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_check_min_next(t_list *lst, int min, int lower)
{
	t_list	*cur;

	cur = lst->next;
	while (cur != lst)
	{
		if (lower < cur->val && cur->val <= min)
			min = cur->val;
		cur = cur->next;
	}
	return (min);
}

static size_t	ps_rank_idx(t_list *lst, int min)
{
	size_t	idx;

	idx = 0;
	while (lst->next->val != min)
	{
		lst = lst->next;
		idx++;
	}
	return (idx);
}

static void	ps_rank_a(t_list *lst, size_t *lst_rank)
{
	int		idx;
	t_list	*cur;

	idx = 0;
	cur = lst;
	while (cur->next != lst)
	{
		cur->next->val = lst_rank[idx++];
		cur = cur->next;
	}	
}

t_list	*ps_lst_rank(t_list *lst, int size)
{
	int		min;
	size_t	*lst_rank;
	size_t	rank;

	rank = 0;
	lst_rank = (size_t *) malloc(sizeof(size_t) * size);
	if (lst_rank == NULL)
		return (NULL);
	min = ps_check_min(lst, INT_MAX);
	while (1)
	{
		if (rank != 0)
			min = ps_check_min_next(lst, INT_MAX, min);
		lst_rank[ps_rank_idx(lst, min)] = rank++;
		if (min == ps_check_max(lst, INT_MIN))
			break ;
	}
	ps_rank_a(lst, lst_rank);
	free(lst_rank);
	return (lst);
}
