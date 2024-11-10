/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:38:40 by masase            #+#    #+#             */
/*   Updated: 2024/11/10 17:46:32 by masase           ###   ########.fr       */
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
