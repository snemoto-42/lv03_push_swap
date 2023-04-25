/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:08:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/04/24 20:55:57 by snemoto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NUM "1234567890"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				val;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

int		ps_atoi(const char *str);

t_list	*ps_lst_add_front(t_list *lst, t_list *new);
t_list	*ps_lst_add_last(t_list *lst, t_list *new);
t_list	*ps_lst_remove_front(t_list *lst);
t_list	*ps_lst_remove_last(t_list *lst);

char	*ps_check_arg(char **argv, int argc, int i);
int		ps_check_sort(t_list *lst);
int		ps_check_min(t_list *a, int min);
int		ps_check_max(t_list *a, int max);
int		ps_lstsize(t_list *lst);

t_list	*ps_lst_init(void);
t_list	*ps_lstnew(char *str);

t_list	*ps_lst_rank(t_list *lst, int size);

void	ps_swap(t_list *lst);
void	ps_rotate(t_list *lst);
void	ps_rotate_reverse(t_list *lst);
void	ps_push(t_list *n1, t_list *n2);
void	ps_operations(t_list *a, t_list *b, char *str);

void	ps_argc_two(t_list *a);
void	ps_argc_three(t_list *a);

void	ps_argc_two_b(t_list *a);
void	ps_argc_two_rev(t_list *a);
void	ps_argc_three_b(t_list *a);
void	ps_argc_three_rev(t_list *b);

t_list	*ps_large_sort(t_list *a, t_list *b, int size);

void	ps_argc_six(t_list *a, t_list *b, int arg);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_isdigit(int c);

#endif
