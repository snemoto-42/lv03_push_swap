/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:57:54 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/22 17:40:17 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lst_print(t_list *lst)
{
	t_list	*cur;
	size_t	i;

	i = 0;
	cur = lst->next;
	while (cur != lst)
	{
		if (i++ > 0)
			write(STDOUT_FILENO, " ", 1);
		ft_printf("%d", cur->val);
		cur = cur->next;
	}
	write(STDOUT_FILENO, "\n", ft_strlen("\n"));
}

// #include <stdio.h>
// printf("	[%d]\n", new->val);

// void	ps_lst_print(t_list *lst);
// int	ft_printf(const char *format, ...);

// ft_printf("	min[%d]\n", min);
// ft_printf("	max[%d]\n", max);
// ps_lst_print(a);
// ps_lst_print(b);

//system("leaks push_swap");

// write(STDOUT_FILENO, "---------\n", ft_strlen("---------\n"));
// system("leaks push_swap");
// write(STDOUT_FILENO, "---------\n", ft_strlen("---------\n"));
