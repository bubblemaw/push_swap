/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_false.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:24:56 by maw               #+#    #+#             */
/*   Updated: 2024/12/01 16:24:11 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rota_push_b_false(t_lista **a, t_lista **b, int r_a, int r_b)
{
	int	price;
	int	x;

	x = 0;
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
	price += rota_left_f(a, b, r_a, r_b);
	price += push_b(a, b, x);
	return (price);
}

int	rota_push_a_false(t_lista **a, t_lista **b, int r_a, int r_b)
{
	int	price;
	int	x;

	x = 0;
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
	price += rota_left_f(a, b, r_a, r_b);
	price += push_a(a, b, x);
	return (price);
}

int	rota_left_f(t_lista **a, t_lista **b, int r_a, int r_b)
{
	int	price;
	int	x;

	x = 0;
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
