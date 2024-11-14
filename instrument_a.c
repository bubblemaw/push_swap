/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrument_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:59:32 by masase            #+#    #+#             */
/*   Updated: 2024/11/14 17:26:50 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_lista **stack_a)
{
	int		nb;
	t_lista	*current_a;
	t_lista	*current_b;

	current_a = *stack_a;
	nb = current_a->nb;
	current_b = current_a->next;
	current_a->nb = current_b->nb;
	current_b->nb = nb;
	return (1);
}

int	push_a(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*temp;

	temp = ft_lstnew_bis((*stack_b)->nb);
	ft_lstadd_front_bis(stack_a, temp);
	deletenod(stack_b);
	return (1);
}

int	rotate_a(t_lista **stack_a)
{
	t_lista	*temp;

	temp = ft_lstnew_bis((*stack_a)->nb);
	ft_lstadd_back_bis(stack_a, temp);
	deletenod(stack_a);
	return (1);
}

int	reverse_rotate_a(t_lista **stack_a)
{
	t_lista	*last;
	t_lista	*temp;

	last = ft_lstlast_bis(*stack_a);
	temp = ft_lstnew_bis(last->nb);
	ft_lstadd_front_bis(stack_a, temp);
	deletenod_last(last);
	return (1);
}
