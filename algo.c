/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:32 by masase            #+#    #+#             */
/*   Updated: 2024/12/05 16:24:44 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_above_max(t_lista **stack_b, int x)
{
	long int		nb;
	int				price;
	t_lista			*temp;

	temp = *stack_b;
	nb = -2147483649;
	price = 0;
	while (1)
	{
		if (temp->nb > nb)
			nb = temp->nb;
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	price = r_b_calculator(nb, stack_b, x);
	return (price);
}

int	pushmiddle_a_to_b(t_lista **stack_a, t_lista **stack_b, int x)
{
	t_lista			*temp;
	int				price;
	long int		nb;

	temp = *stack_b;
	nb = (*stack_b)->nb;
	price = 0;
	while (1)
	{
		if ((*stack_a)->nb > temp->nb && (*stack_a)->nb < temp->prev->nb)
		{
			nb = temp->nb;
		}
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	price = r_b_calculator(nb, stack_b, x);
	return (price);
}

int	pushmiddle_b_to_a(t_lista **stack_a, t_lista **stack_b, int x)
{
	t_lista			*temp;
	int				price;
	long int		nb;

	temp = *stack_a;
	nb = (*stack_a)->nb;
	price = 0;
	while (1)
	{
		if ((*stack_b)->nb < temp->nb && (*stack_b)->nb > temp->prev->nb)
			nb = temp->nb;
		temp = temp->next;
		if (temp == *stack_a)
			break ;
	}
	price = r_a_calculator(nb, stack_a, x);
	return (price);
}

int	rb_push_a_to_b(t_lista **stack_a, t_lista **stack_b, int x)
{
	int	price;

	price = 0;
	if (newmax(stack_a, stack_b) == 1 || newmin(stack_a, stack_b) == 1)
		price += push_above_max(stack_b, x);
	else
		price += pushmiddle_a_to_b(stack_a, stack_b, x);
	return (price);
}

int	ra_push_b_to_a(t_lista **stack_a, t_lista **stack_b, int x)
{
	int	price;
	int	nb;

	price = 0;
	if (newmax(stack_b, stack_a) == 1)
	{
		nb = getmin(stack_a);
		price = r_a_calculator(nb, stack_a, x);
	}
	else if (newmin(stack_b, stack_a) == 1)
	{
		nb = getmin(stack_a);
		price = r_a_calculator(nb, stack_a, x);
	}
	else
		price += pushmiddle_b_to_a(stack_a, stack_b, x);
	return (price);
}
