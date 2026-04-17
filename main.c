/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:15 by iergin            #+#    #+#             */
/*   Updated: 2026/04/17 16:58:48 by iergin           ###   ########.fr       */
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

static void	select_sort(t_stack **stack_a, int *mode, double disorder, t_bench *bench)
{
	int	len;

	len = stack_len(stack_a);
	if (*mode % 10 == 1)
		selection_sort(stack_a, bench);
	else if (*mode % 10 == 2)
		k_sort(stack_a, bench);
	else if (*mode % 10 == 3)
		radix_sort(stack_a, bench);
	else if (*mode % 10 == 0)
	{
		if ((disorder != 0 && disorder < 0.2) || (len <= 5))
			selection_sort(stack_a, bench);
		else if (disorder >= 0.2 && disorder < 0.5)
			k_sort(stack_a, bench);
		else if (disorder >= 0.5)
			radix_sort(stack_a, bench);
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

static void	print_strategy(int mode, double disorder, int len)
{
	if (mode % 10 == 1)
		printf("[bench] strategy: Simple / O(n^2)\n");
	else if (mode % 10 == 2)
		printf("[bench] strategy: Medium / O(n√n)\n");
	else if (mode % 10 == 3)
		printf("[bench] strategy: Complex / O(n log n)\n");
	else if (mode % 10 == 0)
	{
		if (disorder < 0.2 || len <= 5)
			printf("[bench] strategy: Adaptive / O(n^2)\n");
		else if (disorder >= 0.2 && disorder < 0.5)
			printf("[bench] strategy: Adaptive / O(n√n)\n");
		else
			printf("[bench] strategy: Adaptive / O(n log n)\n");
	}
}

static void	benchmark(int mode, double disorder, int len, t_bench *bench)
{
	printf("[bench] disorder: %.2f%%\n", disorder * 100);
	print_strategy(mode, disorder, len);
	printf("[bench] total_ops: %d\n", bench->total_ops);
	printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", 
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}

int	main(int argc, char **args)
{
	t_stack	*stack_a;
	t_bench	*bench;
	t_bench	tbench;
	int		i;
	int		mode;
	double	disorder;
	int		err;

	if (argc == 1 || (argc == 2 && !args[1][0]))
		return (0);
	ft_bzero(&tbench, sizeof(t_bench));
	i = 1;
	mode = 0;
	stack_a = NULL;
	select_mode(args, &mode, &i);
	err = fill_stack(&stack_a, argc, args, i);
	disorder = compute_disorder(&stack_a);
	if (err)
	{
		if (mode >= 10)
			bench = &tbench;
		else
			bench = NULL;
		select_sort(&stack_a, &mode, disorder, bench);
		if (mode >= 10)
			benchmark(mode, disorder, stack_len(&stack_a), bench);
	}
	ft_lstclear(&stack_a);
	return (0);
}
