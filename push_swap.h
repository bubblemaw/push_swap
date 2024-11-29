/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:11:15 by masase            #+#    #+#             */
/*   Updated: 2024/11/29 14:47:05 by masase           ###   ########.fr       */
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

typedef struct s_price
{
	int	bestprice;
	int	bestnb;
	int	r_a;
	int	r_b;
}	t_price;

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
int				checknbmax(t_lista **lst);
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
int				search_bestnb_b(t_lista **stack_a, t_lista **stack_b);
int				search_bestnb_a(t_lista **stack_a, t_lista **stack_b);
int				checkifsorted(t_lista **lst);
int				tri_trois(t_lista **stack_a, int x);
int				getmax(t_lista **stack_b);
int				getmin(t_lista **stack_b);
int				newmax(t_lista **stack_a, t_lista **stack_b);
int				newmin(t_lista **stack_a, t_lista **stack_b);
int				push_from_b_to_a(t_lista **stack_a, t_lista **stack_b, int x);
int				pushmiddle_bis(t_lista **stack_a, t_lista **stack_b, int x);
int				searchnb(t_lista **lst, int nb);
int				rota_b_t(t_lista **a, t_lista **b, int r_a, int r_b);
int				rota_a_t(t_lista **a, t_lista **b, int r_a, int r_b);
int				rota_left_t(t_lista **a, t_lista **b, int r_a, int r_b);
int				rota_b_f(t_lista **a, t_lista **b, int r_a, int r_b);
int				rota_a_f(t_lista **a, t_lista **b, int r_a, int r_b);
int				rota_left_f(t_lista **a, t_lista **b, int r_a, int r_b);

int				rotatefornb_b(t_lista **stack_b, int bestnb, int x);
int				rota(t_lista **stack_a, t_lista **stack_b, int r_a, int r_b);
int				push_above_max(t_lista **stack_b, int x);
void			pricechecking_b(t_lista **a, t_lista **b, t_price *data);
void			pricechecking_a(t_lista **a, t_lista **b, t_price *data);
void			firstsorting(t_lista **stack_a, t_lista **stack_b);
void			secondsorting(t_lista **stack_a, t_lista **stack_b);
int				twoinput(t_lista **lst);
int				threeinput(t_lista **lst);


#endif