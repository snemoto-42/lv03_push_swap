/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 20:05:09 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_lst_init(void)
{
	t_list	*nil;

	nil = (t_list *) malloc(sizeof(t_list));
	if (nil == NULL)
		return (NULL);
	nil->next = nil;
	nil->prev = nil;
	return (nil);
}

t_list	*ps_lstnew(char *str)
{
	t_list	*lst;
	int		nbr;

	nbr = ps_atoi(str);
	if (nbr == 0 && ft_strncmp(str, "0", ft_strlen(str)) != 0)
		return (NULL);
	lst = (t_list *) malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->val = nbr;
	return (lst);
}
