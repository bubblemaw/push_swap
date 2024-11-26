/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maw <maw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:35:04 by masase            #+#    #+#             */
/*   Updated: 2024/11/26 17:24:15 by maw              ###   ########.fr       */
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
	int		price = 0;
	int	r_a = 0;
	int r_b = 0;

	x = 1;
	price = 0;
	price = price / 2;
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
	if (checkifsorted(&stack_a) == 1)
		return (0);
	printf("%d\n", ft_lstsize_bis(stack_a));
	if (ft_lstsize_bis(stack_a) == 2)
	{
		tri_trois(&stack_a, x);
		printlist(stack_a);
		return (0);
	}
	price += push_b(&stack_a, &stack_b, x);
	price += push_b(&stack_a, &stack_b, x);
	while (ft_lstsize_bis(stack_a) >= 3)
	{
		x = 0;
		bestnb = ilfautledire_bis(&stack_a, &stack_b, x);
		copy_a = ft_lst_copy(&stack_a);
		copy_b = ft_lst_copy(&stack_b);
		r_a = lookfornb_a(bestnb, &copy_a, x);
		r_b = push_from_a_to_b(&copy_a, &copy_b, x);
		x = 1;
		price += rota_b_t(&stack_a, &stack_b, r_a, r_b);
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
	}
	price += tri_trois(&stack_a, x);
	while (stack_b)
	{
		x = 0;
		bestnb = ilfautledire(&stack_a, &stack_b, x);
		copy_a = ft_lst_copy(&stack_a);
		copy_b = ft_lst_copy(&stack_b);
		r_b = lookfornb_b(bestnb, &copy_a, x);
		r_a = push_from_b_to_a(&copy_a, &copy_b, x);
		x = 1;
		price += rota_a_t(&stack_a, &stack_b, r_a, r_b);
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
