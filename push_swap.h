/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:11:15 by masase            #+#    #+#             */
/*   Updated: 2024/11/20 20:10:08 by maw              ###   ########.fr       */
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
int				ft_lstsize_bis(t_lista *lst);
t_lista			*ft_lst_copy(t_lista **lst);

int				countwords(const char *str, char c);
int				checkdouble_checknbmax(t_lista **lst);
int				twoargmanager(char *str, t_lista **lst);
int				argmanager(t_lista **lst, int arg, char **argv);
long int		ft_atoi_swap(const char *str);
char			**ft_split(const char *s, char c);

int				error(void);
void			printlist(t_lista *lst);

int				swap_a(t_lista **stack_a, int x);
int				push_a(t_lista **stack_a, t_lista **stack_b, int x);
int				rotate_a(t_lista **stack_a, int x);
int				reverse_rotate_a(t_lista **stack_a, int x);
int				swap_b(t_lista **stack_b, int x);
int				push_b(t_lista **stack_a, t_lista **stack_b, int x);
int				rotate_b(t_lista **stack_b, int x);
int				reverse_rotate_b(t_lista **stack_b, int x);
int				double_swap(t_lista **stack_a, t_lista **stack_b, int x);
int				double_rotate(t_lista **stack_a, t_lista **stack_b, int x);
int				two_reverse_rotate(t_lista **stack_a, t_lista **stack_b, int x);

int				push_from_a_to_b(t_lista **stack_a, t_lista **stack_b, int x);
int				lookfornb_a(int bestnb, t_lista **stack_a, int x);
int				lookfornb_b(int bestnb, t_lista **stack_b, int x);
int				ilfautledire(t_lista **stack_a, t_lista **stack_b, int x);
int				checkifsorted(t_lista **lst);
int				tri_trois(t_lista **stack_a, int x);
int				getmax(t_lista **stack_b);
int				getmin(t_lista **stack_b);
int				push_from_b_to_a(t_lista **stack_a, t_lista **stack_b, int x);
int				pushmiddle_bis(t_lista **stack_a, t_lista **stack_b, int x);
int				searchnb(t_lista **lst, int nb);

#endif