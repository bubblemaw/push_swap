/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findnumbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:23:54 by masase            #+#    #+#             */
/*   Updated: 2024/11/28 18:33:53 by maw              ###   ########.fr       */
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
