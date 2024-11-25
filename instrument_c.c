/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrument_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:03:13 by maw               #+#    #+#             */
/*   Updated: 2024/11/25 15:25:19 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_swap(t_lista **stack_a, t_lista **stack_b, int x)
{
	swap_a(stack_a, x);
	swap_b(stack_b, x);
	if (x == 1)
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (1);
}

int	double_rotate(t_lista **stack_a, t_lista **stack_b, int x)
{
	rotate_a(stack_a, x);
	rotate_b(stack_b, x);
	if (x == 1)
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (1);
}

int	two_reverse_rotate(t_lista **stack_a, t_lista **stack_b, int x)
{
	reverse_rotate_a(stack_a, x);
	reverse_rotate_b(stack_b, x);
	if (x == 1)
	{
		write(1, "rrr\n", 4);
		return (1);
	}
	return (1);
}
