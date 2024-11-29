/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:37:58 by masase            #+#    #+#             */
/*   Updated: 2024/11/29 14:46:43 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	twoinput(t_lista **lst)
{
	swap_a(lst, 1);
	ft_lstclear_bis(lst);
	return (0);
}

int	threeinput(t_lista **lst)
{
	tri_trois(lst, 1);
	ft_lstclear_bis(lst);
	return (0);
}
