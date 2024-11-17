/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:32 by masase            #+#    #+#             */
/*   Updated: 2024/11/17 21:03:54 by masase           ###   ########.fr       */
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
	t_lista	*temp;
	int		price;
	long int		nb;

	temp = *stack_b;
	nb = (*stack_b)->nb;
	price = 0;
	printf("%ld\n", temp->nb);
	printf("%ld\n", (*stack_a)->nb);
	while (temp)
	{
		if ((*stack_a)->nb < temp->nb && (*stack_a)->nb > temp->prev->nb)
			nb = temp->nb;
		temp = temp->next;
	}
	while ((*stack_b)->nb != nb)
		price += rotate_b(stack_b);
	price += push_b(stack_a, stack_b);
	return (price);
}
int	push_from_a_to_b(t_lista **stack_a, t_lista **stack_b)
{
	int	price;

	price = 0;
	if (newmax(stack_a, stack_b) == 1 || newmin(stack_a, stack_b) == 1)
	{
		price += push_above_max(stack_a, stack_b);
		printf("new min ou new max\n");
	}
	else
	{
		price += pushmiddle(stack_a, stack_b);
		printf("on pousse au millieu\n");
	}
	return (price);
}

int	ilfautledire(t_lista **stack_a, t_lista **stack_b)
{
	t_lista *copy_a = NULL;
	t_lista *copy_b = NULL;
	int		price;
	int		bestprice;
	int		nbbase;
	int		bestnb;

	copy_a = ft_lst_copy(stack_a);
	copy_b = ft_lst_copy(stack_b);
	bestprice = push_from_a_to_b(&copy_a, &copy_b);
	nbbase = (*stack_a)->nb;
	bestnb = (*stack_a)->nb;
	ft_lstclear_bis(&copy_a);
	ft_lstclear_bis(&copy_b);
	rotate_a(stack_a);
	while ((*stack_a)->nb != nbbase)
	{
		copy_a = ft_lst_copy(stack_a);
		copy_b = ft_lst_copy(stack_b);
		price = push_from_a_to_b(&copy_a, &copy_b);
		if (price < bestprice)
		{
			bestprice = price;
			bestnb = (*stack_a)->nb;
		}
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
		rotate_a(stack_a);
	}
	return (bestnb);

}
int	lookfornb(int bestnb, t_lista **stack_a)
{
	int		price;

	price = 0;
	while(*stack_a)
	{
		if (bestnb == (*stack_a)->nb)
			return (price);
		price += rotate_a(stack_a);
	}
	return (0);

}
