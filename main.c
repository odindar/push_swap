/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:15 by iergin            #+#    #+#             */
/*   Updated: 2026/04/18 16:17:01 by iergin           ###   ########.fr       */
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

static void	select_sort(t_stack **stack_a, int *mode, double dorder, t_bench *b)
{
	int	len;

	len = stack_len(stack_a);
	if (*mode % 10 == 1)
		selection_sort(stack_a, b);
	else if (*mode % 10 == 2)
		k_sort(stack_a, b);
	else if (*mode % 10 == 3)
		radix_sort(stack_a, b);
	else if (*mode % 10 == 0)
	{
		if ((dorder != 0 && dorder < 0.2) || (len <= 5))
			selection_sort(stack_a, b);
		else if (dorder >= 0.2 && dorder < 0.5)
			k_sort(stack_a, b);
		else if (dorder >= 0.5)
			radix_sort(stack_a, b);
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

static void	benchmark(int mode, double dorder, int len, t_bench *b)
{
	fprintf(stderr, "[bench] disorder: %.2f%%\n", dorder * 100);
	if (mode % 10 == 1)
		fprintf(stderr, "[bench] strategy: Simple / O(n^2)\n");
	else if (mode % 10 == 2)
		fprintf(stderr, "[bench] strategy: Medium / O(n√n)\n");
	else if (mode % 10 == 3)
		fprintf(stderr, "[bench] strategy: Complex / O(n log n)\n");
	else if (mode % 10 == 0)
	{
		if (dorder < 0.2 || len <= 5)
			fprintf(stderr, "[bench] strategy: Adaptive / O(n^2)\n");
		else if (dorder >= 0.2 && dorder < 0.5)
			fprintf(stderr, "[bench] strategy: Adaptive / O(n√n)\n");
		else
			fprintf(stderr, "[bench] strategy: Adaptive / O(n log n)\n");
	}
	fprintf(stderr, "[bench] total_ops: %d\n", b->total_ops);
	fprintf(stderr, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		b->sa, b->sb, b->ss, b->pa, b->pb);
	fprintf(stderr, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}

int	main(int argc, char **args)
{
	t_stack	*stack_a;
	t_bench	*b;
	t_bench	tb;
	int		i;
	int		mode;
	double	dorder;
	int		err;

	if (argc == 1 || (argc == 2 && !args[1][0]))
		return (0);
	ft_bzero(&tb, sizeof(t_bench));
	i = 1;
	mode = 0;
	stack_a = NULL;
	select_mode(args, &mode, &i);
	err = fill_stack(&stack_a, argc, args, i);
	dorder = compute_disorder(&stack_a);
	if (err)
	{
		if (mode >= 10)
			b = &tb;
		else
			b = NULL;
		select_sort(&stack_a, &mode, dorder, b);
		if (mode >= 10)
			benchmark(mode, dorder, stack_len(&stack_a), b);
	}
	ft_lstclear(&stack_a);
	return (0);
}
