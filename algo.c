/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:32 by masase            #+#    #+#             */
/*   Updated: 2024/11/15 01:05:27 by maw              ###   ########.fr       */
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

int	push_from_a_to_b(t_lista **stack_a, t_lista **stack_b)
{
	int	price;

	price = 0;
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	printlist(*stack_a);
	printlist(*stack_b);
	while (ft_lstsize_bis(*stack_a) > 3)
	{
		while (!((*stack_a)->nb > (*stack_b)->nb))
		{
			price += rotate_b(stack_b);
		}
		price += push_b(stack_a, stack_b);
		if (*stack_a)
			(*stack_a) = (*stack_a)->next;
	}
	return (price);
}
