/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:47:32 by masase            #+#    #+#             */
/*   Updated: 2024/11/24 16:50:58 by masase           ###   ########.fr       */
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

int	push_above_max(t_lista **stack_a, t_lista **stack_b, int x)
{
	int		nb;
	int		price;
	t_lista	*chocolat;
	t_lista	*temp;

	chocolat = *stack_a;
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
	// while (*stack_b)
	// {
	// 	if ((*stack_b)->nb == nb)
	// 		break ;
	// 	price += rotate_b(stack_b, x);
	// }
	// price += push_b(stack_a, stack_b, x);
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
			nb = temp->nb;
		temp = temp->next;
		if (temp == *stack_b)
			break ;
	}
	price = rotatefornb_b(stack_b, nb, x);
	// while ((*stack_b)->nb != nb)
	// 	price += rotate_b(stack_b, x);
	// price += push_b(stack_a, stack_b, x);
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
	while ((*stack_a)->nb != nb)
		price += rotate_a(stack_a, x);
	price += push_a(stack_a, stack_b, x);
	return (price);
}
int	push_from_a_to_b(t_lista **stack_a, t_lista **stack_b, int x)
{
	int	price;

	price = 0;
	if (newmax(stack_a, stack_b) == 1 || newmin(stack_a, stack_b) == 1)
	{
		price += push_above_max(stack_a, stack_b, x);
		// printf("new min ou new max\n");
	}
	else
	{
		price += pushmiddle(stack_a, stack_b, x);
		// printf("on pousse au millieu\n");
	}
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
		price += lookfornb_a(nb, stack_a, x);
		price += push_a(stack_a, stack_b, x);
		// printf("new max\n");
	}
	else if (newmin(stack_b, stack_a) == 1)
	{
		nb = getmin(stack_a);
		price += lookfornb_a(nb, stack_a, x);
		price += push_a(stack_a, stack_b, x);
		// printf("new min\n");
	}
	else
	{
		price += pushmiddle_bis(stack_a, stack_b, x);
		// printf("on pousse au millieu\n");
	}
	return (price);
}

int	ilfautledire_bis(t_lista **stack_a, t_lista **stack_b, int x)
{
	/*il faut surment que je remplace le price par r_a et r_b pour mieux calculer les rapports et vrmt
	sortir le nombre qui va me couter le moins de cout*/
	
	while ((*stack_a)->nb != nbbase)
	{
		copy_a = ft_lst_copy(stack_a);
		copy_b = ft_lst_copy(stack_b);
		r_a = lookfornb_a(bestnb, &copy_a, x);
		r_b = push_from_a_to_b(&copy_a, &copy_b, x);
		price = rotator(cop);
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);

		copy_a = ft_lst_copy(stack_a);
		copy_b = ft_lst_copy(stack_b);
		price = push_from_a_to_b(&copy_a, &copy_b, x);
		if (price < bestprice)
		{
			bestprice = price;
			bestnb = (*stack_a)->nb;
		}
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
		rotate_a(stack_a, x);
	}
	return (bestnb);
}
int	ilfautledire(t_lista **stack_a, t_lista **stack_b, int x)
{
	/*il faut surment que je remplace le price par r_a et r_b pour mieux calculer les rapports et vrmt
	sortir le nombre qui va me couter le moins de cout*/
	t_lista *copy_a = NULL;
	t_lista *copy_b = NULL;
	int		price;
	int		bestprice;
	int		nbbase;
	int		bestnb;

	copy_a = ft_lst_copy(stack_a);
	copy_b = ft_lst_copy(stack_b);
	bestprice = push_from_a_to_b(&copy_a, &copy_b, x);
	nbbase = (*stack_a)->nb;
	bestnb = (*stack_a)->nb;
	ft_lstclear_bis(&copy_a);
	ft_lstclear_bis(&copy_b);
	rotate_a(stack_a, x);
	while ((*stack_a)->nb != nbbase)
	{
		copy_a = ft_lst_copy(stack_a);
		copy_b = ft_lst_copy(stack_b);
		price = push_from_a_to_b(&copy_a, &copy_b, x);
		if (price < bestprice)
		{
			bestprice = price;
			bestnb = (*stack_a)->nb;
		}
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
		rotate_a(stack_a, x);
	}
	return (bestnb);
}

int checkifsorted(t_lista **lst)
{
	int	nb;

	nb = (*lst)->nb;
	*lst = (*lst)->next;
	while (*lst)
	{
		if (nb == (*lst)->nb)
			break ;
		if (nb < (*lst)->nb)
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

int	rotator(t_lista **stack_a, t_lista **stack_b, int r_a, int r_b, int x)
{
	int price;

	price = 0;
	while (r_a > 0 && r_b > 0)
	{
		price += double_rotate(stack_a, stack_b, x);
		r_a--;
		r_b--;
	}
	while (r_a < 0 && r_b < 0)
	{
		price += two_reverse_rotate(stack_a, stack_b, x);
		r_a++;
		r_b++;
	}
	while (r_a > 0)
	{
		price += rotate_a(stack_a, x);
		r_a--;
	}
	while (r_b > 0)
	{
		price += rotate_b(stack_b, x);
		r_b--;
	}
	while (r_a < 0)
	{
		price += reverse_rotate_a(stack_a, x);
		r_a++;
	}
	while (r_b < 0)
	{
		price += reverse_rotate_b(stack_b, x);
		r_b++;
	}
	price += push_b(stack_a, stack_b, x);
	return (price);
}

int	rotate_push(t_lista **stack_a, t_lista **stack_b, int r_a, int r_b, int x)
{
	int	price;

	price = 0;
	while (r_a > 0)
	{
		price += rotate_a(stack_a, x);
		r_a--;
	}
	while (r_b > 0)
	{
		price += rotate_b(stack_b, x);
		r_b--;
	}
	while (r_a < 0)
	{
		price += reverse_rotate_a(stack_a, x);
		r_a--;
	}
	while (r_b < 0)
	{
		price += reverse_rotate_b(stack_b, x);
		r_b--;
	}
	price += push_b(stack_a, stack_b, x);
	return (price);
}
