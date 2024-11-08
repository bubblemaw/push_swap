/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:11:15 by masase            #+#    #+#             */
/*   Updated: 2024/11/08 16:24:21 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "LIBFT/libft.h"

typedef struct s_lista
{
	int				nb;
	struct s_lista	*next;
}					t_lista;

t_lista	*ft_lstnew_bis(int nb);
void	ft_lstadd_front_bis(t_lista **lst, t_lista *new);
int		countworda(const char *str, char c);
void	printlist(t_lista *lst);
void	twoargmanager(char *str, t_lista **lst);
int		ft_atoi_swap(const char *str);

#endif