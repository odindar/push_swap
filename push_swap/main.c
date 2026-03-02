/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:15 by iergin            #+#    #+#             */
/*   Updated: 2026/03/02 11:39:40 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // bu silinecek

int	main(int argc, char **args)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	int	num;

	if (argc == 1 || (argc == 2 && !args[1][0]))
		return (0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		// burada int olup olmadığı int min int max duplicate kontrolü yapılacak
		num = ft_atoi(args[i]);
		append_node(&stack_a, num);
		i++;
	}
	//sa(&stack_a);
	//pb(&stack_a,&stack_b);
	//pa(&stack_a,&stack_b);
	printf("%f\n", compute_disorder(&stack_a));
	//rra(&stack_a);
	//printf("%f", compute_disorder(&stack_a));
	while (stack_a)
	{
		printf("%d\n", (int)stack_a->content);
		stack_a = stack_a->next;
	}
	printf("b : \n");
	while (stack_b)
	{
		printf("%d\n", (int)stack_b->content);
		stack_b = stack_b->next;
	}
	return (0);
}
