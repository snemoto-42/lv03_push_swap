/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:07:26 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 20:57:34 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_exit_failure(t_list *a, t_list *b)
{
	t_list	*cur;
	t_list	*tmp;

	free(b);
	cur = a;
	while (cur->next != a)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	write(STDOUT_FILENO, "Error\n", ft_strlen("Error\n"));
	exit(EXIT_FAILURE);
	return ;
}

static void	ps_exit_success(void)
{
	exit(EXIT_SUCCESS);
}

static void	ps_sort(t_list *a, t_list *b, int argc)
{
	if (argc - 1 == 2)
		ps_argc_two(a);
	else if (argc - 1 == 3)
		ps_argc_three(a);
	else if (argc - 1 < 7)
		ps_argc_six(a, b, argc - 1);
	else
	{
		if (ps_lst_rank(a, ps_lstsize(a)) == NULL)
			ps_exit_failure(a, b);
		if (ps_large_sort(a, b, ps_lstsize(a)) == NULL)
			ps_exit_failure(a, b);
	}
	ps_exit_success();
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	int		i;

	a = ps_lst_init();
	b = ps_lst_init();
	if (a == NULL || b == NULL)
		ps_exit_failure(a, b);
	i = 1;
	while (i < argc)
	{
		if (ps_check_arg(argv, argc, i) == NULL)
			ps_exit_failure(a, b);
		tmp = ps_lst_add_last(a, ps_lstnew(argv[i]));
		if (tmp == NULL)
			ps_exit_failure(a, b);
		i++;
	}
	if (ps_check_sort(a))
		ps_exit_success();
	ps_sort(a, b, argc);
}
