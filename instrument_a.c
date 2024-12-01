/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrument_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:59:32 by masase            #+#    #+#             */
/*   Updated: 2024/12/01 15:16:32 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_lista **stack_a, int x)
{
	int		nb;
	t_lista	*current_a;
	t_lista	*current_b;

	current_a = *stack_a;
	nb = current_a->nb;
	current_b = current_a->next;
	current_a->nb = current_b->nb;
	current_b->nb = nb;
	if (x == 1)
	{
		write(1, "sa\n", 3);
		return (1);
	}
	return (1);
}

int	push_a(t_lista **stack_a, t_lista **stack_b, int x)
{
	t_lista	*temp;

	temp = ft_lstnew_bis((*stack_b)->nb);
	ft_lstadd_front_bis(stack_a, temp);
	deletenod(stack_b);
	if (x == 1)
	{
		write(1, "pa\n", 3);
		return (1);
	}
	return (1);
}

int	rotate_a(t_lista **stack_a, int x)
{
	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return (0);
	*stack_a = (*stack_a)->next;
	if (x == 1)
	{
		write(1, "ra\n", 3);
		return (1);
	}
	return (1);
}

int	reverse_rotate_a(t_lista **stack_a, int x)
{
	t_lista	*last;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return (0);
	last = (*stack_a)->prev;
	last->prev->next = *stack_a;
	(*stack_a)->prev = last->prev;
	last->next = *stack_a;
	last->prev = (*stack_a)->prev;
	(*stack_a)->prev->next = last;
	(*stack_a)->prev = last;
	*stack_a = last;
	if (x == 1)
	{
		write(1, "rra\n", 4);
		return (1);
	}
	return (1);
}
