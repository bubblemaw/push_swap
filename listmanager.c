/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:20:56 by masase            #+#    #+#             */
/*   Updated: 2024/11/18 16:22:09 by masase           ###   ########.fr       */
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
	t_lista	*start;

	if (!lst || !*lst)
		return ;

	start = *lst;
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


void	ft_lstdelone_bis(t_lista *lst)
{
	free(lst);
}
t_lista	*ft_lstlast_bis(t_lista *lst)
{
	t_lista	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
void	ft_lstadd_back_bis(t_lista **lst, t_lista *new)
{
	t_lista	*last;

	if (!lst || !new)
		return ;

	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
		return ;
	}
	last = (*lst)->prev;
	last->next = new;
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
}

int	ft_lstsize_bis(t_lista *lst)
{
	int		i;
	t_lista	*temp;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_lista	*ft_lst_copy(t_lista **lst)
{
	t_lista	*temp;
	t_lista	*newnod;
	t_lista	*newhead;

	if (!lst || !*lst)
		return (NULL);
	temp = *lst;
	newhead = ft_lstnew_bis((temp->nb));
	if (!newhead)
		return (NULL);
	temp = temp->next;
	while (temp != *lst)
	{
		newnod = ft_lstnew_bis((temp->nb));
		if (!newnod)
			return (NULL);
		ft_lstadd_back_bis(&newhead, newnod);
		temp = temp->next;
	}
	return (newhead);
}
