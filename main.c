/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masase <masase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:35:04 by masase            #+#    #+#             */
/*   Updated: 2024/11/29 16:00:50 by masase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ft_lstsize_bis(stack_a) == 2)
		return (twoinput(&stack_a));
	if (ft_lstsize_bis(stack_a) == 3)
		return (threeinput(&stack_a));
	firstsorting(&stack_a, &stack_b);
	tri_trois(&stack_a, 1);
	secondsorting(&stack_a, &stack_b);
	ft_lstclear_bis(&stack_a);
	ft_lstclear_bis(&stack_b);
	return (0);
}

void	firstsorting(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*copy_a;
	t_lista	*copy_b;
	int		bestnb;
	int		r_a;
	int		r_b;

	r_a = 0;
	r_b = 0;
	push_b(stack_a, stack_b, 1);
	push_b(stack_a, stack_b, 1);
	while (ft_lstsize_bis(*stack_a) > 3)
	{
		bestnb = search_bestnb_a(stack_a, stack_b);
		copy_a = ft_lst_copy(stack_a);
		copy_b = ft_lst_copy(stack_b);
		r_a = lookfornb_a(bestnb, &copy_a, 0);
		r_b = push_from_a_to_b(&copy_a, &copy_b, 0);
		rota_b_t(stack_a, stack_b, r_a, r_b);
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
	}
}

void	secondsorting(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*copy_a;
	t_lista	*copy_b;
	int		bestnb;
	int		r_a;
	int		r_b;

	r_a = 0;
	r_b = 0;
	while (*stack_b)
	{
		bestnb = search_bestnb_b(stack_a, stack_b);
		copy_a = ft_lst_copy(stack_a);
		copy_b = ft_lst_copy(stack_b);
		r_b = lookfornb_b(bestnb, &copy_a, 0);
		r_a = push_from_b_to_a(&copy_a, &copy_b, 0);
		rota_a_t(stack_a, stack_b, r_a, r_b);
		ft_lstclear_bis(&copy_a);
		ft_lstclear_bis(&copy_b);
	}
	bestnb = getmin(stack_a);
	lookfornb_a(bestnb, stack_a, 1);
}
