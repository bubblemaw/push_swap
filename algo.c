/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:32 by masase            #+#    #+#             */
/*   Updated: 2024/11/15 13:32:43 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
pousser les deux premiers  element sur stack b
comparer tete stack a avec elements stack b
si nouveau max ou nouveau min pousser au dessus de min ou de max stack b
faire un programme qui compte le nombre de coup pour chaque nombre present dans stack A
sytsteme de credit
Il faut que je fasse passer les noeuds et pas copier les nombres
*/
/*
Nouveau maximum compare le chifrre avec toute la liste
calcul du nombre de coup pour bon endroit

*/

#include "push_swap.h"

int	newmax(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*temp;

	temp = *stack_b;

	while (temp)
	{
		if ((temp)->nb > (*stack_a)->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	newmin(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*temp;

	temp = *stack_b;

	while (temp)
	{
		if ((temp)->nb < (*stack_a)->nb)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int push_above_max(t_lista **stack_a, t_lista **stack_b)
{
	int nb;
	t_lista *temp;

	temp = *stack_b;
	nb = 0;
	while (temp)
	{
		if (temp->nb > nb)
			nb = temp->nb;
		temp = temp->next;
	}
	while (*stack_b)
	{
		if ((*stack_b)->nb == nb)
			break ;
		rotate_b(stack_b);
	}
	push_b(stack_a, stack_b);
	return (1);
}

int	push_from_a_to_b(t_lista **stack_a, t_lista **stack_b)
{
	int	price;

	price = 0;
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	// price += push_above_max(stack_a, stack_b);
	// printlist(*stack_a);
	// printlist(*stack_b);
	while (ft_lstsize_bis(*stack_a) > 3)
	{
		if (newmax(stack_a, stack_b) == 1)
			price += push_above_max(stack_a, stack_b);
		if (newmin(stack_a, stack_b) == 1)
			price += push_above_max(stack_a, stack_b);
		while (!((*stack_a)->nb > (*stack_b)->nb))
		{
			if ((*stack_a)->nb < (*stack_b)->nb)
				break ;
			price += rotate_b(stack_b);
		}
		price += push_b(stack_a, stack_b);
		(*stack_a) = (*stack_a)->next;
	}
	return (price);
}
