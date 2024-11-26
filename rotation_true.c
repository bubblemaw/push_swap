/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_true.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:02:52 by maw               #+#    #+#             */
/*   Updated: 2024/11/26 16:48:02 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rota_b_t(t_lista **a, t_lista **b, int r_a, int r_b)
{
	int	price;
	int	x;

	x = 1;
	price = 0;
	while (r_a > 0 && r_b > 0)
	{
		price += double_rotate(a, b, x);
		r_a--;
		r_b--;
	}
	while (r_a < 0 && r_b < 0)
	{
		price += two_reverse_rotate(a, b, x);
		r_a++;
		r_b++;
	}
	while (r_a > 0)
	{
		price += rotate_a(a, x);
		r_a--;
	}
	price += rota_left_t(a, b, r_a, r_b);
	price += push_b(a, b, x);
	return (price);
}

int	rota_a_t(t_lista **a, t_lista **b, int r_a, int r_b)
{
	int	price;
	int	x;

	x = 1;
	price = 0;
	while (r_a > 0 && r_b > 0)
	{
		price += double_rotate(a, b, x);
		r_a--;
		r_b--;
	}
	while (r_a < 0 && r_b < 0)
	{
		price += two_reverse_rotate(a, b, x);
		r_a++;
		r_b++;
	}
	while (r_a > 0)
	{
		price += rotate_a(a, x);
		r_a--;
	}
	price += rota_left_t(a, b, r_a, r_b);
	price += push_a(a, b, x);
	return (price);
}

int	rota_left_t(t_lista **a, t_lista **b, int r_a, int r_b)
{
	int	price;
	int	x;

	x = 1;
	price = 0;
	while (r_b > 0)
	{
		price += rotate_b(b, x);
		r_b--;
	}
	while (r_a < 0)
	{
		price += reverse_rotate_a(a, x);
		r_a++;
	}
	while (r_b < 0)
	{
		price += reverse_rotate_b(b, x);
		r_b++;
	}
	return (price);
}

