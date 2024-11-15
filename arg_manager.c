/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:40:29 by maw               #+#    #+#             */
/*   Updated: 2024/11/14 18:39:34 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	i = countwords(str, 32) - 1;
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