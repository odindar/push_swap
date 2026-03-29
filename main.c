/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:15 by iergin            #+#    #+#             */
/*   Updated: 2026/03/29 17:06:04 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h> // SİL

int	main(int argc, char **args)
{
	int		i;
	t_stack	*stack_a;
	int		num;
	int		mode;
	double	disorder;

	if (argc == 1 || (argc == 2 && !args[1][0]))
		return (0);
	i = 1;
	mode = 0;
	stack_a = NULL;
	if (argc > 1) {
		if (ft_strncmp(args[1], "--simple", 9) == 0)
		{
			mode = 1;
			i = 2;
		}
		else if (ft_strncmp(args[1], "--medium", 9) == 0)
		{
			mode = 2;
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
	}
	while (i < argc)
	{
		num = simple_atoi(args[i]);
		if (has_available(stack_a, num) && num != -1)
			append_node(&stack_a, num);
		else
		{
			write(2, "Error\n", 6);
			ft_lstclear(&stack_a, free);
			return (0);
		}
		i++;
	}
	disorder = compute_disorder(&stack_a);
	if (mode == 1)
		selection_sort(&stack_a);
	else if (mode == 2)
		k_sort(&stack_a);
	else if (mode == 3)
		radix_sort(&stack_a);
	else if (mode == 0)
	{
		if (disorder != 0 && disorder < 0.2)
			selection_sort(&stack_a);
		else if (disorder >= 0.2 && disorder < 0.5)
			k_sort(&stack_a);
		else if (disorder >= 0.5)
			radix_sort(&stack_a);
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
