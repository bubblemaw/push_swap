/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   price_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:03:21 by maw               #+#    #+#             */
/*   Updated: 2024/11/28 18:06:08 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_bestnb_a(t_lista **stack_a, t_lista **stack_b)
{
	t_price	data;
	int		nbbase;

	data.bestprice = 999;
	data.bestnb = (*stack_a)->nb;
	data.r_a = 0;
	data.r_b = 0;
	nbbase = (*stack_a)->nb;

	while (1)
	{
		pricechecking_a(stack_a, stack_b, &data);
		data.r_a++;
		if ((*stack_a)->nb == nbbase)
			break ;
	}
	return (data.bestnb);
}

void	pricechecking_a(t_lista **a, t_lista **b, t_price *data)
{
	t_lista	*copy_a;
	t_lista	*copy_b;
	int		price;

	copy_a = ft_lst_copy(a);
	copy_b = ft_lst_copy(b);
	data->r_b = push_from_a_to_b(&copy_a, &copy_b, 0);
	price = rota_b_f(&copy_a, &copy_b, data->r_a, data->r_b);
	if (price < data->bestprice)
	{
		data->bestprice = price;
		data->bestnb = (*a)->nb;
	}
	ft_lstclear_bis(&copy_a);
	ft_lstclear_bis(&copy_b);
}

int	search_bestnb_b(t_lista **stack_a, t_lista **stack_b)
{
	t_price	data;
	int		nbbase;

	data.bestprice = 999;
	data.bestnb = (*stack_a)->nb;
	data.r_a = 0;
	data.r_b = 0;
	nbbase = (*stack_a)->nb;
	while (1)
	{
		pricechecking_b(stack_a, stack_b, &data);
		rotate_a(stack_a, 0);
		data.r_a++;
		if ((*stack_a)->nb == nbbase)
			break ;
	}
	return (data.bestnb);
}

void	pricechecking_b(t_lista **a, t_lista **b, t_price *data)
{
	t_lista	*copy_a;
	t_lista	*copy_b;
	int		price;

	copy_a = ft_lst_copy(a);
	copy_b = ft_lst_copy(b);
	data->r_b = push_from_b_to_a(&copy_a, &copy_b, 0);
	price = rota_a_f(&copy_a, &copy_b, data->r_a, data->r_b);
	if (price < data->bestprice)
	{
		data->bestprice = price;
		data->bestnb = (*a)->nb;
	}
	ft_lstclear_bis(&copy_a);
	ft_lstclear_bis(&copy_b);
}
