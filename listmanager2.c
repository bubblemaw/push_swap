/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanager2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:30:05 by masase            #+#    #+#             */
/*   Updated: 2024/12/05 16:25:45 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone_bis(t_lista *lst)
{
	if (!lst)
		return ;
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
	while (1)
	{
		temp = temp->next;
		i++;
		if (temp == lst)
			break ;
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
