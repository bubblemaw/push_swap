/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:40:29 by maw               #+#    #+#             */
/*   Updated: 2024/12/05 16:24:52 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkdouble_checknbmax(t_lista **lst)
{
	t_lista	*temp;
	t_lista	*current;

	current = *lst;
	while (1)
	{
		temp = current->next;
		while (temp != *lst)
		{
			if (temp->nb == current->nb)
			{
				ft_lstclear_bis(lst);
				return (0);
			}
			temp = temp->next;
		}
		current = current->next;
		if (current == *lst)
			break ;
	}
	return (checknbmax(lst));
}

int	checknbmax(t_lista **lst)
{
	t_lista	*current;

	current = *lst;
	while (1)
	{
		if (current->nb < -2147483648 || current->nb > 2147483647)
		{
			ft_lstclear_bis(lst);
			return (0);
		}
		current = current->next;
		if (current == *lst)
			break ;
	}
	return (1);
}

void	freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	twoargmanager(char *str, t_lista **lst)
{
	int		i;
	char	**tab;
	t_lista	*new_node;

	i = 0;
	tab = NULL;
	i = countwords(str, 32) - 1;
	tab = ft_split(str, ' ');
	if (!tab)
		return (0);
	while (i >= 0)
	{
		new_node = ft_lstnew_bis(ft_atoi_swap(tab[i]));
		if (!new_node || new_node->nb == ERROR_NB)
		{
			deletenod(&new_node);
			ft_lstclear_bis(lst);
			freetab(tab);
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
		if (!new_node || new_node->nb == ERROR_NB)
		{
			deletenod(&new_node);
			ft_lstclear_bis(lst);
			return (0);
		}
		ft_lstadd_front_bis(lst, new_node);
		i--;
	}
	return (1);
}
