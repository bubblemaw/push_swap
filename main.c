/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:35:04 by masase            #+#    #+#             */
/*   Updated: 2024/11/08 11:22:24 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
comment est-ce que je ressoit les informations un argument a separe ou plusieur arguments
traiter les informations
convertir les informations en int
mettres les int dans une liste chainee dans le bon sens

ALGORITHME

*/
#include "push_swap.h"

int main(int argc, char **argv)
{
	char **tab;
	int i;
	t_list *current;

	
	tab = NULL;
	i = 0;
	if (argc < 2)
	{
		ft_pustr("Error\n");
		return (0)
	}
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		while (i > 0)
			current = (ft_atoi(tab[i]));// creer un nouveau noeud avec les noouveau int
			ft_lstadd_front(current);

	}

	if (argc > 2)
	{

	}
}