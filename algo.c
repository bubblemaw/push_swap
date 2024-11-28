/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:32 by masase            #+#    #+#             */
/*   Updated: 2024/11/28 18:10:22 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_above_max(t_lista **stack_b, int x)
{
	int		nb;
	int		price;
	t_lista	*temp;

	temp = *stack_b;
	nb = 0;
	price = 0;
	while (1)
	{
		if (temp->nb > nb)
			nb = temp->nb;
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	price = rotatefornb_b(stack_b, nb, x);
	return (price);
}

int	pushmiddle(t_lista **stack_a, t_lista **stack_b, int x)
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
	price = rotatefornb_b(stack_b, nb, x);
	return (price);
}

int	pushmiddle_bis(t_lista **stack_a, t_lista **stack_b, int x)
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
	price = rotatefornb_b(stack_a, nb, x);
	return (price);
}

int	push_from_a_to_b(t_lista **stack_a, t_lista **stack_b, int x)
{
	int	price;

	price = 0;
	if (newmax(stack_a, stack_b) == 1 || newmin(stack_a, stack_b) == 1)
		price += push_above_max(stack_b, x);
	else
		price += pushmiddle(stack_a, stack_b, x);
	return (price);
}

int	push_from_b_to_a(t_lista **stack_a, t_lista **stack_b, int x)
{
	int	price;
	int	nb;

	price = 0;
	if (newmax(stack_b, stack_a) == 1)
	{
		nb = getmin(stack_a);
		price = lookfornb_a(nb, stack_a, x);
	}
	else if (newmin(stack_b, stack_a) == 1)
	{
		nb = getmin(stack_a);
		price = lookfornb_a(nb, stack_a, x);
	}
	else
		price += pushmiddle_bis(stack_a, stack_b, x);
	return (price);
}
