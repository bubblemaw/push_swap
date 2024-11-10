/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:35:04 by masase            #+#    #+#             */
/*   Updated: 2024/11/10 21:34:58 by masase           ###   ########.fr       */
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
		printf("%ld ->", lst->nb);
		lst = lst->next;
	}
	printf("NULL\n");
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int	twoargmanager(char *str, t_lista **lst)
{
	int		i;
	char	**tab;
	t_lista	*new_node;

	i = 0;
	tab = NULL;
	i = countworda(str, 32) - 1;
	tab = ft_split(str, ' ');
	if (!tab)
		return (0);
	while (i >= 0)
	{
		new_node = ft_lstnew_bis(ft_atoi_swap(tab[i]));
		if (new_node->nb == ERROR_NB)
		{
			ft_lstclear_bis(lst);
			return (0);
		}
		ft_lstadd_front_bis(lst, new_node);
		i--;
	}
	freetab(tab);
	return (1);
}

int	argmanager(t_lista **lst, int arg, char **argv)
{
	int		i;
	t_lista	*new_node;

	i = arg - 1;
	while (i > 0)
	{
		new_node = ft_lstnew_bis(ft_atoi_swap(argv[i]));
		if (new_node->nb == ERROR_NB)
		{
			ft_lstclear_bis(lst);
			return (0);
		}
		ft_lstadd_front_bis(lst, new_node);
		i--;
	}
	return (1);
}

int	checkdouble_checknbmax(t_lista **lst)
{
	t_lista	*temp;
	t_lista	*current;

	current = *lst;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (temp->nb == current->nb)
				return (0);
			temp = temp->next;
		}
	current = current->next;
	}
	current = *lst;
	while (current)
	{
		if (current->nb < -2147483648 || current->nb > 2147483647)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_lista	*current;

	current = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2 && twoargmanager(argv[1], &current) == 0)
		return (error());
	else if (argc > 2 && argmanager(&current, argc, argv) == 0)
		return (error());
	if (checkdouble_checknbmax(&current) == 0)
		return (error());
	printlist(current);
	return (0);
}


