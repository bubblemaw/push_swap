/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:32 by masase            #+#    #+#             */
/*   Updated: 2024/11/26 17:39:06 by maw              ###   ########.fr       */
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

int	push_above_max(t_lista **stack_b, int x)
{
	int		nb;
	int		price;
	t_lista	*temp;

	temp = *stack_b;
	nb = 0;
	price = 0;
	while (1)
	{
		if (temp->nb > nb)
			nb = temp->nb;
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	price = rotatefornb_b(stack_b, nb, x);
	return (price);
}

int	pushmiddle(t_lista **stack_a, t_lista **stack_b, int x)
{
	t_lista			*temp;
	int				price;
	long int		nb;

	temp = *stack_b;
	nb = (*stack_b)->nb;
	price = 0;
	while (1)
	{
		if ((*stack_a)->nb > temp->nb && (*stack_a)->nb < temp->prev->nb)
		{
			nb = temp->nb;
		}
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	price = rotatefornb_b(stack_b, nb, x);
	return (price);
}

int	pushmiddle_bis(t_lista **stack_a, t_lista **stack_b, int x)
{
	t_lista			*temp;
	int				price;
	long int		nb;

	temp = *stack_a;
	nb = (*stack_a)->nb;
	price = 0;
	while (1)
	{
		if ((*stack_b)->nb < temp->nb && (*stack_b)->nb > temp->prev->nb)
			nb = temp->nb;
		temp = temp->next;
		if (temp == *stack_a)
			break ;
	}
	price = rotatefornb_b(stack_a, nb, x);
	return (price);
}

int	push_from_a_to_b(t_lista **stack_a, t_lista **stack_b, int x)
{
	int	price;

	price = 0;
	if (newmax(stack_a, stack_b) == 1 || newmin(stack_a, stack_b) == 1)
		price += push_above_max(stack_b, x);
	else
		price += pushmiddle(stack_a, stack_b, x);
	return (price);
}

int	push_from_b_to_a(t_lista **stack_a, t_lista **stack_b, int x)
{
	int	price;
	int	nb;

	price = 0;
	if (newmax(stack_b, stack_a) == 1)
	{
		nb = getmin(stack_a);
		price = lookfornb_a(nb, stack_a, x);
	}
	else if (newmin(stack_b, stack_a) == 1)
	{
		nb = getmin(stack_a);
		price = lookfornb_a(nb, stack_a, x);
	}
	else
		price += pushmiddle_bis(stack_a, stack_b, x);
	return (price);
}

int	ilfautledire_bis(t_lista **stack_a, t_lista **stack_b, int x)
{
	t_lista *copy_a = NULL;
	t_lista *copy_b = NULL;
	int	r_a = 0;
	int	r_b = 0;
	int price = 0;
	int bestprice = 999;
	int nbbase;
	int bestnb = (*stack_a)->nb;
	nbbase = (*stack_a)->nb;

	while (1)
	{
		copy_a = ft_lst_copy(stack_a);
		copy_b = ft_lst_copy(stack_b);
		r_b = push_from_a_to_b(&copy_a, &copy_b, x);
		price = rota_b_f(&copy_a, &copy_b, r_a, r_b);
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
		if (price < bestprice)
		{
			bestprice = price;
			bestnb = (*stack_a)->nb;
		}
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
		rotate_a(stack_a, x);
		r_a++;
		if ((*stack_a)->nb == nbbase)
			break ;
	}
	return (bestnb);
}
int	ilfautledire(t_lista **stack_a, t_lista **stack_b, int x)
{
	t_lista *copy_a = NULL;
	t_lista *copy_b = NULL;
	int	r_a = 0;
	int	r_b = 0;
	int price = 0;
	int bestprice = 999;
	int nbbase;
	int bestnb = (*stack_a)->nb;
	nbbase = (*stack_a)->nb;
	while (1)
	{
		copy_a = ft_lst_copy(stack_a);
		copy_b = ft_lst_copy(stack_b);
		r_b = push_from_b_to_a(&copy_a, &copy_b, x);
		price = rota_a_f(&copy_a, &copy_b, r_a, r_b);
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
		if (price < bestprice)
		{
			bestprice = price;
			bestnb = (*stack_a)->nb;
		}
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
		rotate_a(stack_a, x);
		r_a++;
		if ((*stack_a)->nb == nbbase)
			break ;
	}
	return (bestnb);
}

int checkifsorted(t_lista **lst)
{
	int		nb;
	t_lista	*temp;

	temp = *lst;
	nb = (*lst)->nb;
	*lst = (*lst)->next;

	while (1)
	{
		if (*lst == temp)
			break ;
		if (nb > (*lst)->nb)
			return (0);
		nb = (*lst)->nb;
		*lst = (*lst)->next;
	}
	return (1);
}

int tri_trois(t_lista **ls, int x)
{
	int	price;

	price = 0;
	if ((*ls)->nb < (*ls)->next->nb && (*ls)->next->nb < (*ls)->prev->nb)
		return (price);
	else if ((*ls)->nb > (*ls)->next->nb && (*ls)->next->nb > (*ls)->prev->nb)
		price += reverse_rotate_a(ls, x);
	else if ((*ls)->nb > (*ls)->prev->nb && (*ls)->prev->nb > (*ls)->next->nb)
		price += rotate_a(ls, x);
	else if ((*ls)->next->nb > (*ls)->nb && (*ls)->nb > (*ls)->prev->nb)
		price += reverse_rotate_a(ls, x);
	else if ((*ls)->next->nb > (*ls)->prev->nb && (*ls)->prev->nb > (*ls)->nb)
	{
		price += reverse_rotate_a(ls, x);
		price += swap_a(ls, x);
	}
	else if ((*ls)->prev->nb > (*ls)->nb && (*ls)->nb > (*ls)->next->nb)
		price += swap_a(ls, x);
	return (price);
}
