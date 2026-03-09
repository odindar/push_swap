/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:15 by iergin            #+#    #+#             */
/*   Updated: 2026/03/09 11:16:44 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // bu silinecek

int	main(int argc, char **args)
{
	int		i;
	t_list	*stack_a;
	int	num;
	int	mode;
	double	disorder;

	if (argc == 1 || (argc == 2 && !args[1][0]))
		return (0);
	i = 1;
	mode = 0;
	stack_a = NULL;
	while (argc > 1) {
		if (ft_strncmp(args[1], "--simple", 9) == 0)
		{
			mode = 1;
			i = 2;
		}
		else if (ft_strncmp(args[1], "--complex", 10) == 0)
		{
			mode = 3;
			i = 2;
		}
		else if (ft_strncmp(args[1], "--adaptive", 11) == 0)
		{
			mode = 0;
			i = 2;
		}
		break;
	}
	while (i < argc)
	{
		// burada int olup olmadığı int min int max duplicate kontrolü yapılacak
		num = ft_atoi(args[i]);
		append_node(&stack_a, num);
		i++;
	}
	//printf("%d\n", stack_len(&stack_a));
	//printf("%d\n", stack_min(&stack_a));
	disorder = compute_disorder(&stack_a);
	if (mode == 1)
		selection_sort(&stack_a);
	else if (mode == 3)
		radix_sort(&stack_a);
	else if (mode == 0)
	{
		if (disorder < 0.2)
			selection_sort(&stack_a);
		else if (disorder > 0.2 && disorder < 0.5)
			printf("medium\n");
		else if (disorder > 0.5)
			radix_sort(&stack_a);
	}
	//printf("a : \n");
	//while (stack_a)
	//{
		//printf("%d\n", (int)stack_a->content);
		//stack_a = stack_a->next;
	//}
	return (0);
}
