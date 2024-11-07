/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:35:04 by masase            #+#    #+#             */
/*   Updated: 2024/11/07 17:28:29 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

comment est-ce que je ressoit les informations un argument a separe ou plusieur arguments
traiter les informations
convertir les informations en int
mettres les int dans une liste chainee dans le bon sens

ALGORITHME



*/
int main(int argc, char **argv)
{
	char **tab;
	int i;
	
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
			ft_lstnew(ft_atoi(tab[i]))// creer un nouveau noeud avec les noouveau int
			ft_lstaddfront

	}

	if (argc > 2)
	{

	}
}