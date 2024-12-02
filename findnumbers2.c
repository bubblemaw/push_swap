/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findnumbers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:34:11 by maw               #+#    #+#             */
/*   Updated: 2024/12/02 16:00:24 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_a_calculator(int bestnb, t_lista **stack_a, int x)
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

int	r_b_calculator(int bestnb, t_lista **stack_b, int x)
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
