/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:08:30 by snemoto           #+#    #+#             */
/*   Updated: 2023/03/21 14:28:15 by snemoto          ###   ########.fr       */
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

t_list	*ps_lst_init(void);
t_list	*ps_lstnew(char *str);
void	ft_error(void);
void	ps_find_error(char **argv, int argc, int i);
void	ps_sort(t_list *a, t_list *b, int argc);

t_list	*ps_lst_add_front(t_list *lst, t_list *new);
t_list	*ps_lst_remove_front(t_list *lst);
t_list	*ps_lst_add_last(t_list *lst, t_list *new);
t_list	*ps_lst_remove_last(t_list *lst);

void	ps_swap(t_list *n1, t_list *n2);
void	ps_rotate(t_list *lst);
void	ps_rotate_reverse(t_list *lst);
void	ps_push(t_list *n1, t_list *n2);

void	ps_operations(t_list *a, t_list *b, char *str);
void	ps_argc_two(t_list *a);
void	ps_argc_three(t_list *a);
void	ps_argc_six(t_list *a, t_list *b, int argc);
void	ps_insertion_sort(t_list *a, t_list *b);

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char c);

void	ps_lst_print(t_list	*lst);
int		ft_printf(const char *format, ...);

#endif
