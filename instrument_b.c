/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrument_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:02:50 by maw               #+#    #+#             */
/*   Updated: 2024/11/25 15:25:05 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_b(t_lista **stack_b, int x)
{
	int		nb;
	t_lista	*current_a;
	t_lista	*current_b;

	current_a = *stack_b;
	nb = current_a->nb;
	current_b = current_a->next;
	current_a->nb = current_b->nb;
	current_b->nb = nb;
	if (x == 1)
	{
		write(1, "sb\n", 3);
		return (1);
	}
	return (1);
}

int	push_b(t_lista **stack_a, t_lista **stack_b, int x)
{
	t_lista	*temp;

	temp = ft_lstnew_bis((*stack_a)->nb);
	ft_lstadd_front_bis(stack_b, temp);
	deletenod(stack_a);
	if (x == 1)
	{
		write(1, "pb\n", 3);
		return (1);
	}
	return (1);
}

int	rotate_b(t_lista **stack_b, int x)
{
	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return (0);
	*stack_b = (*stack_b)->next;
	if (x == 1)
	{
		write(1, "rb\n", 3);
		return (1);
	}
	return (1);
}

int	reverse_rotate_b(t_lista **stack_b, int x)
{
	t_lista	*last;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return (0);
	last = (*stack_b)->prev;

	last->prev->next = *stack_b;
	(*stack_b)->prev = last->prev;

	last->next = *stack_b;
	last->prev = (*stack_b)->prev;
	(*stack_b)->prev->next = last;
	(*stack_b)->prev = last;
	*stack_b = last;
	if (x == 1)
	{
		write(1, "rrb\n", 4);
		return (1);
	}
	return (1);
}

