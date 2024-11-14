/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrument_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:03:13 by maw               #+#    #+#             */
/*   Updated: 2024/11/14 17:26:12 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_swap(t_lista **stack_a, t_lista **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	return (1);
}

int	double_rotate(t_lista **stack_a, t_lista **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	return (1);
}

int	double_reverse_rotate(t_lista **stack_a, t_lista **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	return (1);
}
