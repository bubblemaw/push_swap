/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrument_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:03:13 by maw               #+#    #+#             */
/*   Updated: 2024/11/28 15:54:18 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_swap(t_lista **stack_a, t_lista **stack_b, int x)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (x == 1)
	{
		write(1, "ss\n", 3);
		return (1);
	}
	return (1);
}

int	double_rotate(t_lista **stack_a, t_lista **stack_b, int x)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (x == 1)
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (1);
}

int	two_reverse_rotate(t_lista **stack_a, t_lista **stack_b, int x)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	if (x == 1)
	{
		write(1, "rrr\n", 4);
		return (1);
	}
	return (1);
}
