/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:33:37 by masase            #+#    #+#             */
/*   Updated: 2024/11/04 17:59:03 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dernier;

	if (!lst || !new)
		return ;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	dernier = ft_lstlast(*lst);
	dernier->next = new;
	new->next = NULL;
}
