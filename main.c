/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:35:04 by masase            #+#    #+#             */
/*   Updated: 2024/11/20 17:57:12 by maw              ###   ########.fr       */
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

void	printlist(t_lista *lst)
{
	t_lista	*first;

	if (!lst)
	{
		printf("NULL\n");
		return ;
	}
	first = lst;
	while (1)
	{
		printf("%ld ->", lst->nb);
		lst = lst->next;
		if (lst == first)
			break ;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_lista	*stack_a;
	t_lista	*stack_b;
	int		bestnb;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2 && twoargmanager(argv[1], &stack_a) == 0)
		return (error());
	else if (argc > 2 && argmanager(&stack_a, argc, argv) == 0)
		return (error());
	if (checkdouble_checknbmax(&stack_a) == 0)
		return (error());
	printf("liste de base \n");
	printlist(stack_a);
	printlist(stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	printf("liste apres deux premier push\n");
	printlist(stack_a);
	printlist(stack_b);
	while (ft_lstsize_bis(stack_a) >= 3)
	{
		bestnb = ilfautledire(&stack_a, &stack_b);
		printf("%d est le meilleure numero a pousse\n ", bestnb);
		lookfornb_a(bestnb, &stack_a);
		printf("je modifie les liste pour push le bon nb\n");
		printlist(stack_a);
		printlist(stack_b);
		push_from_a_to_b(&stack_a, &stack_b);
		printf("LISTE APRES PUSH\n");
		printlist(stack_a);
		printlist(stack_b);
	}
	tri_trois(&stack_a);
	printf("LISTE APRES TRIS TROIS\n");
	printlist(stack_a);
	printlist(stack_b);
	while (stack_b)
		push_from_b_to_a(&stack_a, &stack_b);
	bestnb = getmin(&stack_a);
	printf("%d\n", bestnb);
	lookfornb_a(bestnb, &stack_a);
	printlist(stack_a);
	printlist(stack_b);
	return (0);
}


