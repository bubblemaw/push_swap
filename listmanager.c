/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmanager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:20:56 by masase            #+#    #+#             */
/*   Updated: 2024/11/14 16:59:54 by maw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_bis(t_lista **lst, t_lista *new)
{
	if (new == NULL)
		return ;
	if (*lst != NULL)
		(*lst)->prev = new;
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

t_lista	*ft_lstnew_bis(long int nb)
{
	t_lista	*nod;

	nod = malloc(sizeof(t_lista));
	if (nod == NULL)
		return (NULL);
	nod->nb = nb;
	nod->next = NULL;
	nod->prev = NULL;
	return (nod);
}

void	ft_lstclear_bis(t_lista **lst)
{
	t_lista	*temp;

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

	temp = (*nod)->next;
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
	t_lista	*dernier;

	if (!lst || !new)
		return ;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	dernier = ft_lstlast_bis(*lst);
	dernier->next = new;
	new->next = NULL;
}

// int	main(void)
// {
//     t_list	*node = ft_lstnew(malloc(10)); // Création d'un nœud avec du contenu dynamique

//     ft_lstdelone(node, ft_free_content);   // Suppression du nœud avec ft_lstdelone
//     return (0);
// }