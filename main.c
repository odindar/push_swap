/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:15 by iergin            #+#    #+#             */
/*   Updated: 2026/04/16 13:09:26 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	select_mode(char **args, int *mode, int *i)
{
	while (args[*i] && ft_strncmp(args[*i], "--", 2) == 0)
	{
		if (ft_strncmp(args[*i], "--simple", 9) == 0)
			*mode = (*mode / 10) * 10 + 1;
		else if (ft_strncmp(args[*i], "--medium", 9) == 0)
			*mode = (*mode / 10) * 10 + 2;
		else if (ft_strncmp(args[*i], "--complex", 10) == 0)
			*mode = (*mode / 10) * 10 + 3;
		else if (ft_strncmp(args[*i], "--adaptive", 11) == 0)
			*mode = (*mode / 10) * 10 + 0;
		else if (ft_strncmp(args[*i], "--bench", 8) == 0)
			*mode += 10;
		(*i)++;
	}
}

static void	select_sort(t_stack **stack_a, int *mode, double disorder)
{
	if (*mode % 10 == 1)
		selection_sort(stack_a);
	else if (*mode % 10 == 2)
		k_sort(stack_a);
	else if (*mode % 10 == 3)
		radix_sort(stack_a);
	else if (*mode % 10 == 0)
	{
		if (disorder != 0 && disorder < 0.2)
			selection_sort(stack_a);
		else if (disorder >= 0.2 && disorder < 0.5)
			k_sort(stack_a);
		else if (disorder >= 0.5)
			radix_sort(stack_a);
	}
}

static int	fill_stack(t_stack **stack_a, int argc, char **args, int i)
{
	int	num;

	while (i < argc)
	{
		num = simple_atoi(args[i]);
		if (!(has_available(*stack_a, num) && num != -1
				&& append_node(stack_a, num)))
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	print_strategy(int mode, double disorder)
{
	if (mode % 10 == 1)
		printf("[bench] strategy: Simple / O(n^2)\n");
	else if (mode % 10 == 2)
		printf("[bench] strategy: Medium / O(n√n)\n");
	else if (mode % 10 == 3)
		printf("[bench] strategy: Complex / O(n log n)\n");
	else if (mode % 10 == 0)
	{
		if (disorder < 0.2)
			printf("[bench] strategy: Adaptive / O(n^2)\n");
		else if (disorder >= 0.2 && disorder < 0.5)
			printf("[bench] strategy: Adaptive / O(n√n)\n");
		else
			printf("[bench] strategy: Adaptive / O(n log n)\n");
	}
}

static void	benchmark(int mode, double disorder)
{
	int	total_ops;

	total_ops = 0;
	printf("[bench] disorder: %.2f%%\n", disorder * 100);
	print_strategy(mode, disorder);
	printf("[bench] total_ops: %d\n", total_ops);
	printf("[bench] sa: 0 sb: 0 ss: 0 pa: 0 pb: 0\n");
	printf("[bench] ra: 0 rb: 0 rr: 0 rra: 0 rrb: 0 rrr: 0\n");
}

int	main(int argc, char **args)
{
	t_stack	*stack_a;
	int		i;
	int		mode;
	double	disorder;
	int		err;

	if (argc == 1 || (argc == 2 && !args[1][0]))
		return (0);
	i = 1;
	mode = 0;
	stack_a = NULL;
	select_mode(args, &mode, &i);
	err = fill_stack(&stack_a, argc, args, i);
	disorder = compute_disorder(&stack_a);
	if (err)
	{
		select_sort(&stack_a, &mode, disorder);
		if (mode >= 10)
			benchmark(mode, disorder);
	}
	ft_lstclear(&stack_a);
	return (0);
}
