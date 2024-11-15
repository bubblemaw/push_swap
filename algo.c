/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:32 by masase            #+#    #+#             */
/*   Updated: 2024/11/15 16:54:07 by masase           ###   ########.fr       */
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
on fait les actions avec tous les elements de la liste A
on prend  celui qui prend le moins de coup
pour faire cela des que je sais quelle nb prend le moins de coup
je teste ca sur une liste fictive que je libere ensuite
je retourne ce nb a la fonction
et je fais en sorte d'executer les commandes pour ce nb
et on repete jusqua 
il faut que retienne le price et le nb
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

int	push_above_max(t_lista **stack_a, t_lista **stack_b)
{
	int		nb;
	t_lista	*temp;

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
int	pushmiddle(t_lista **stack_a, t_lista **stack_b)
{
	int	price;
	int	i;
	int	maxrotate;

	maxrotate = (ft_lstsize_bis(*stack_b) / 2);
	i = 0;
	price = 0;
	while (i < maxrotate)
	{
		if ((*stack_a)->nb < (*stack_b)->nb)
		{
			price += push_b(stack_a, stack_b);
			return (price);
		}
		i++;
		price += rotate_b(stack_b);
	}
	return (price);
}
int	push_from_a_to_b(t_lista **stack_a, t_lista **stack_b)
{
	int	price;

	price = 0;
	// price += push_above_max(stack_a, stack_b);
	// printlist(*stack_a);
	// printlist(*stack_b);
		if (newmax(stack_a, stack_b) == 1)
			price += push_above_max(stack_a, stack_b);
		else if (newmin(stack_a, stack_b) == 1)
			price += push_above_max(stack_a, stack_b);
		else
			price += pushmiddle(stack_a, stack_b);
	return (price);
}

int	ilfautledire(t_lista **stack_a, t_lista **stack_b)
{
	t_lista *copy_a;
	t_lista *copy_b;
	int		price;
	int		bestprice;
	int		nb;
	int		bestnb;

	copy_a = ft_lst_copy(stack_a);
	copy_b = ft_lst_copy(stack_b);
	while (copy_a)
	{
		price = push_from_a_to_b(&copy_a, &copy_b);
		nb = copy_a->nb;
		if (price < bestprice)
		{
			bestprice = price;
			bestnb = nb;
		}
		copy_a = copy_a->next;
	}
	ft_lstclear_bis(&copy_a);
	ft_lstclear_bis(&copy_b);
	return (bestnb);// la j'ai le meilleure nombre a envoyer dans la colonne b je dois donc iteter dans la co
					// dans la colonne A pour le trouver et l'envoyer dans la colonne_B
}
