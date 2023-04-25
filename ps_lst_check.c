/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 17:47:47 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ps_check_arg(char **argv, int argc, int i)
{
	int	j;

	j = i + 1;
	if (ft_strlen(argv[i]) > ft_strlen("-2147483648"))
		return (NULL);
	while (j < argc)
	{
		if (ft_strlen(argv[i]) < ft_strlen(argv[j]) \
			&& ft_strncmp(argv[i], argv[j], ft_strlen(argv[j])) == 0)
			return (NULL);
		else if (ft_strlen(argv[i]) >= ft_strlen(argv[j]) \
			&& ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
			return (NULL);
		j++;
	}
	j = 0;
	if (ft_strchr("-", argv[i][j]) != NULL)
		j++;
	while (argv[i][j] != '\0')
	{				
		if (ft_strchr(NUM, argv[i][j]) == NULL)
			return (NULL);
		j++;
	}
	return (*argv);
}

int	ps_check_sort(t_list *lst)
{
	t_list	*cur;
	int		max;

	cur = lst->next;
	max = INT_MIN;
	while (cur != lst)
	{
		if (cur->val >= max)
			max = cur->val;
		else
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	ps_check_min(t_list *a, int min)
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

int	ps_check_max(t_list *a, int max)
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

int	ps_lstsize(t_list *lst)
{
	size_t	size;
	t_list	*cur;

	size = 0;
	cur = lst->next;
	while (cur != lst)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}
