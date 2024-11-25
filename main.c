/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:35:04 by masase            #+#    #+#             */
/*   Updated: 2024/11/25 18:38:43 by masase           ###   ########.fr       */
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
	t_lista *copy_a = NULL;
	t_lista *copy_b = NULL;
	int		bestnb;
	int		x;
	int		price;
	int	r_a = 0;
	int r_b = 0;

	x = 1;
	price = 0;
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
	// printf("liste de base \n");
	// printlist(stack_a);
	// printlist(stack_b);
	price += push_b(&stack_a, &stack_b, x);
	price += push_b(&stack_a, &stack_b, x);
	// printf("liste apres deux premier push\n");
	// printlist(stack_a);
	// printlist(stack_b);
	while (ft_lstsize_bis(stack_a) >= 3)
	{
		x = 0;
		bestnb = ilfautledire_bis(&stack_a, &stack_b, x);
		// printf("%d est le meilleure numero a pousse\n ", bestnb);
		copy_a = ft_lst_copy(&stack_a);
		copy_b = ft_lst_copy(&stack_b);
		// printf("A =  %d et B = %d\n", r_a, r_b);
		r_a = lookfornb_a(bestnb, &copy_a, x);
		// printf("je modifie les liste pour push le bon nb\n");
		// printlist(stack_a);
		// printlist(stack_b);
		r_b = push_from_a_to_b(&copy_a, &copy_b, x);
		x = 1;
		// printf("A =  %d et B = %d\n", r_a, r_b);
		price += rotator(&stack_a, &stack_b, r_a, r_b, x);
		// printf("A =  %d et B = %d\n", r_a, r_b);
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
		// price += rotate_push(&stack_a, &stack_b, r_a, r_b, x);
		// printf("LISTE APRES PUSH\n");
		// printlist(stack_a);
		// printlist(stack_b);
	}
	price += tri_trois(&stack_a, x);
	// printf("LISTE APRES TRIS TROIS\n");
	// printlist(stack_a);
	// printlist(stack_b);
	// printf("Nombre de coup: %d\n", price);
	while (stack_b)
	{
		x = 0;
		bestnb = ilfautledire(&stack_a, &stack_b, x);
		// printf("%d est le meilleure numero a pousse\n ", bestnb);
		copy_a = ft_lst_copy(&stack_a);
		copy_b = ft_lst_copy(&stack_b);
		// printf("A =  %d et B = %d\n", r_a, r_b);
		r_b = lookfornb_b(bestnb, &copy_a, x);
		// printf("je modifie les liste pour push le bon nb\n");
		// printlist(stack_a);
		// printlist(stack_b);
		r_a = push_from_b_to_a(&copy_a, &copy_b, x);
		x = 1;
		// printf("A =  %d et B = %d\n", r_a, r_b);
		price += rotator_bis(&stack_a, &stack_b, r_a, r_b, x);
		// printf("A =  %d et B = %d\n", r_a, r_b);
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
	}
	bestnb = getmin(&stack_a);
	// printf("%d\n", bestnb);
	price += lookfornb_a(bestnb, &stack_a, x);
	printlist(stack_a);
	// printlist(stack_b);
	// printf("Nombre de coup: %d\n", price);
	return (0);
}
