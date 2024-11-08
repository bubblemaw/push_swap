/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:35:04 by masase            #+#    #+#             */
/*   Updated: 2024/11/08 16:23:38 by masase           ###   ########.fr       */
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

int	countworda(const char *str, char c)
{
	size_t	i;
	size_t	count;
	int		in;

	in = 0;
	i = 0;
	count = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		if (str[i] != c && in == 0)
		{
			count++;
			in = 1;
		}
		else if (str[i] == c)
			in = 0;
		i++;
	}
	return (count);
}

void	printlist(t_lista *lst)
{
	while (lst)
	{
		printf("%d ->", lst->nb);
		lst = lst->next;
	}
	printf("NULL\n");
}

void	twoargmanager(char *str, t_lista **lst)
{
	int		i;
	char	**tab;
	t_lista	*new_node;

	i = 0;
	tab = NULL;
	i = countworda(str, 32) - 1;
	tab = ft_split(str, ' ');
	if (!tab)
		return ;
	while (i >= 0)
	{
		new_node = ft_lstnew_bis(ft_atoi_swap(tab[i]));
		ft_lstadd_front_bis(lst, new_node);
		i--;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

void	argmanager(t_lista **lst, int arg, char **argv)
{
	int		i;
	t_lista	*new_node;

	i = arg - 1;
	while (i > 0)
	{
		new_node = ft_lstnew_bis(ft_atoi_swap(argv[i]));
		ft_lstadd_front_bis(lst, new_node);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_lista	*current;


	current = NULL;
	i = 0;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		twoargmanager(argv[1], &current);
	else if (argc > 2)
		argmanager(&current, argc, argv);
	printlist(current);
	return (0);

}
