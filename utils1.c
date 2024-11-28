/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:38:40 by masase            #+#    #+#             */
/*   Updated: 2024/11/28 18:08:19 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

long int	ft_atoi_swap(const char *str)
{
	int			i;
	long int	signe;
	long int	resultat;

	resultat = 0;
	signe = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i])
	{
		resultat = resultat * 10 + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9')
			return (ERROR_NB);
		i++;
	}
	return (resultat * signe);
}

int	checkifsorted(t_lista **lst)
{
	int		nb;
	t_lista	*temp;

	temp = *lst;
	nb = temp->nb;
	temp = temp->next;
	while (1)
	{
		if (*lst == temp)
			break ;
		if (nb > temp->nb)
			return (0);
		nb = temp->nb;
		temp = temp->next;
	}
	return (1);
}

int	tri_trois(t_lista **ls, int x)
{
	int	price;

	price = 0;
	if ((*ls)->nb < (*ls)->next->nb && (*ls)->next->nb < (*ls)->prev->nb)
		return (price);
	else if ((*ls)->nb > (*ls)->next->nb && (*ls)->next->nb > (*ls)->prev->nb)
	{
		price += rotate_a(ls, x);
		price += swap_a(ls, x);
	}
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
