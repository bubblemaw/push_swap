/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:38:40 by masase            #+#    #+#             */
/*   Updated: 2024/11/08 16:57:11 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_atoi_swap(const char *str)
{
	int	i;
	int	signe;
	int	resultat;

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
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		resultat *= 10;
		resultat = (str[i] - '0') + resultat;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (error());
	return (resultat * signe);
}
