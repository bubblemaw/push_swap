/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findnumbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:23:54 by masase            #+#    #+#             */
/*   Updated: 2024/11/24 16:51:00 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getmax(t_lista **stack_b)
{
	t_lista	*temp;
	int		nb;

	temp = *stack_b;
	nb = temp->nb;
	while (1)
	{
		if ((temp)->nb > nb)
			nb = temp->nb;
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	return (nb);
}
int	getmin(t_lista **stack_b)
{
	t_lista	*temp;
	int		nb;

	temp = *stack_b;
	nb = temp->nb;
	while (1)
	{
		if ((temp)->nb < nb)
			nb = temp->nb;
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	return (nb);
}

int	newmax(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*temp;

	temp = *stack_b;
	while (1)
	{
		if ((temp)->nb > (*stack_a)->nb)
			return (0);
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	return (1);
}

int	newmin(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*temp;

	temp = *stack_b;
	while (1)
	{
		if ((temp)->nb < (*stack_a)->nb)
			return (0);
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	return (1);
}

int	searchnb(t_lista **lst, int nb)
{
	t_lista	*current;
	int		i;

	i = 0;
	current = *lst;
	while (1)
	{
		current = current->next;
		i++;
		if (nb == current->nb)
			return (i);
		if (current == *lst)
			break ;
	}
	return (i);
}

int	lookfornb_a(int bestnb, t_lista **stack_a, int x)
{
	int		r_a;
	int		i;
	int		size;

	size = ft_lstsize_bis(*stack_a);
	r_a = 0;
	if ((*stack_a)->next->nb == bestnb)
	{
		swap_a(stack_a, x);
		return (0);
	}
	i = searchnb(stack_a, bestnb);
	if (i <= size / 2)
	{
		while ((*stack_a)->nb != bestnb)
		{
			rotate_a(stack_a, x);
			r_a++;
		}
	}
	else
	{
		i = size - i;
		while ((*stack_a)->nb != bestnb)
		{
			reverse_rotate_a(stack_a, x);
			r_a--;
		}
	}
	return (r_a);
}

int	lookfornb_b(int bestnb, t_lista **stack_b, int x)
{
	int		price;
	int		i;
	int		size;

	size = ft_lstsize_bis(*stack_b);
	price = 0;
	if ((*stack_b)->next->nb == bestnb)
		return (price += swap_b(stack_b, x));
	i = searchnb(stack_b, bestnb);
	if (i <= size / 2)
	{
		while ((*stack_b)->nb != bestnb)
			price += rotate_b(stack_b, x);
	}
	else
	{
		i = size - i;
		while ((*stack_b)->nb != bestnb)
			price += reverse_rotate_a(stack_b, x);
	}
	return (price);
}

int	rotatefornb_b(t_lista **stack_b, int bestnb, int x)
{
	int	i;
	int	size;
	int r_b = 0;

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
		i = size - i;
		while ((*stack_b)->nb != bestnb)
		{
			reverse_rotate_b(stack_b, x);
			r_b--;
		}
	}
	return (r_b);
}
