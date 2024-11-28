/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findnumbers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:34:11 by maw               #+#    #+#             */
/*   Updated: 2024/11/28 19:19:34 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lookfornb_a(int bestnb, t_lista **stack_a, int x)
{
	int		r_a;
	int		i;
	int		size;

	size = ft_lstsize_bis(*stack_a);
	r_a = 0;
	i = searchnb(stack_a, bestnb);
	if (i <= size / 2)
	{
		while ((*stack_a)->nb != bestnb)
			r_a += rotate_a(stack_a, x);
	}
	else
	{
		while ((*stack_a)->nb != bestnb)
			r_a -= reverse_rotate_a(stack_a, x);
	}
	return (r_a);
}

int	lookfornb_b(int bestnb, t_lista **stack_b, int x)
{
	int		r_b;
	int		i;
	int		size;

	size = ft_lstsize_bis(*stack_b);
	r_b = 0;
	i = searchnb(stack_b, bestnb);
	if (i <= size / 2)
	{
		while ((*stack_b)->nb != bestnb)
			r_b += rotate_b(stack_b, x);
	}
	else
	{
		while ((*stack_b)->nb != bestnb)
			r_b -= reverse_rotate_a(stack_b, x);
	}
	return (r_b);
}

int	rotatefornb_b(t_lista **stack_b, int bestnb, int x)
{
	int	i;
	int	size;
	int	r_b;

	r_b = 0;
	size = ft_lstsize_bis(*stack_b);
	i = searchnb(stack_b, bestnb);
	if (i <= size / 2)
	{
		while ((*stack_b)->nb != bestnb)
		{
			rotate_b(stack_b, x);
			r_b++;
		}
	}
	else
	{
		while ((*stack_b)->nb != bestnb)
		{
			reverse_rotate_b(stack_b, x);
			r_b--;
		}
	}
	return (r_b);
}