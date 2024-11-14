/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:11:15 by masase            #+#    #+#             */
/*   Updated: 2024/11/14 17:53:45 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "LIBFT/libft.h"
# define ERROR_NB -2147483649L

typedef struct s_lista
{
	long int		nb;
	struct s_lista	*next;
	struct s_lista	*prev;
}					t_lista;

void			ft_lstclear_bis(t_lista **lst);
void			ft_lstdelone_bis(t_lista *lst);
t_lista			*ft_lstnew_bis(long int nb);
void			ft_lstadd_front_bis(t_lista **lst, t_lista *new);
void			ft_lstadd_back_bis(t_lista **lst, t_lista *new);
t_lista			*ft_lstlast_bis(t_lista *lst);
void			deletenod_last(t_lista *nod);
void			deletenod(t_lista **nod);

int				countworda(const char *str, char c);
int				checkdouble_checknbmax(t_lista **lst);
int				twoargmanager(char *str, t_lista **lst);
int				argmanager(t_lista **lst, int arg, char **argv);
long int		ft_atoi_swap(const char *str);
char			**ft_split(const char *s, char c);

int				error(void);
void			printlist(t_lista *lst);

int				swap_a(t_lista **stack_a);
int				push_a(t_lista **stack_a, t_lista **stack_b);
int				rotate_a(t_lista **stack_a);
int				reverse_rotate_a(t_lista **stack_a);
int				swap_b(t_lista **stack_b);
int				push_b(t_lista **stack_a, t_lista **stack_b);
int				rotate_b(t_lista **stack_b);
int				reverse_rotate_b(t_lista **stack_b);
int				double_swap(t_lista **stack_a, t_lista **stack_b);
int				double_rotate(t_lista **stack_a, t_lista **stack_b);
int				double_reverse_rotate(t_lista **stack_a, t_lista **stack_b);

#endif