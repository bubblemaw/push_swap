/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:20:56 by masase            #+#    #+#             */
/*   Updated: 2024/11/29 14:32:11 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_bis(t_lista **lst, t_lista *new)
{
	t_lista	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
	}
	else
	{
		last = (*lst)->prev;
		new->next = *lst;
		new->prev = last;
		last->next = new;
		(*lst)->prev = new;
		*lst = new;
	}
}

t_lista	*ft_lstnew_bis(long int nb)
{
	t_lista	*nod;

	nod = malloc(sizeof(t_lista));
	if (nod == NULL)
		return (NULL);
	nod->nb = nb;
	nod->next = nod;
	nod->prev = nod;
	return (nod);
}

void	ft_lstclear_bis(t_lista **lst)
{
	t_lista	*temp;

	if (!lst || !*lst)
		return ;
	if ((*lst)->prev)
		(*lst)->prev->next = NULL;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone_bis(*lst);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}

void	deletenod(t_lista **nod)
{
	t_lista	*temp;

	if (!nod || !*nod)
		return ;

	if ((*nod)->next == *nod)
	{
		free(*nod);
		*nod = NULL;
		return ;
	}

	temp = (*nod)->next;
	(*nod)->prev->next = temp;
	temp->prev = (*nod)->prev;
	free(*nod);
	*nod = temp;
}

void	deletenod_last(t_lista *nod)
{
	t_lista	*temp;

	temp = nod->prev;
	temp->next = NULL;
	free(nod);
}


