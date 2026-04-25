/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:15 by iergin            #+#    #+#             */
/*   Updated: 2026/04/24 23:55:00 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_mode(char **args, t_bench *b, int *i)
{
	while (args[*i] && ft_strncmp(args[*i], "--", 2) == 0)
	{
		if (ft_strncmp(args[*i], "--simple", 9) == 0)
			b->strategy = 1;
		else if (ft_strncmp(args[*i], "--medium", 9) == 0)
			b->strategy = 2;
		else if (ft_strncmp(args[*i], "--complex", 10) == 0)
			b->strategy = 3;
		else if (ft_strncmp(args[*i], "--adaptive", 11) == 0)
			b->strategy = 0;
		else if (ft_strncmp(args[*i], "--bench", 8) == 0)
			b->is_bench = 1;
		else if (ft_strncmp(args[*i], "--count-only", 13) == 0)
			b->count_only = 1;
		else
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		(*i)++;
	}
}

static void	select_sort(t_stack **stack_a, int str, double dorder, t_bench *b)
{
	if (str == 1)
		selection_sort(stack_a, b);
	else if (str == 2)
		k_sort(stack_a, b);
	else if (str == 3)
		radix_sort(stack_a, b);
	else if (str == 0)
	{
		if (dorder < 0.2 || stack_len(stack_a) <= 5 )
			selection_sort(stack_a, b);
		else if (dorder >= 0.2 && dorder < 0.5)
			k_sort(stack_a, b);
		else if (dorder >= 0.5)
			radix_sort(stack_a, b);
	}
}

static int	fill_stack(t_stack **stack_a, int argc, char **args, int i)
{
	char	**split_args;

	while (i < argc)
	{
		split_args = ft_split(args[i], ' ');
		if (!split_args || !split_args[0])
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a);
			free_split(split_args);
			return (-1);
		}
		if (!split(stack_a, split_args))
			return (-1);
		free_split(split_args);
		i++;
	}
	if (is_sorted(*stack_a))
	{
		ft_lstclear(stack_a);
		return (0);
	}
	return (1);
}

static void	benchmark(int strategy, int len, double dorder, t_bench *b)
{
	ft_printf(2, "[bench] disorder: %f%%\n", dorder * 100);
	if (strategy == 1)
		ft_printf(2, "[bench] strategy: Simple / O(n^2)\n");
	else if (strategy == 2)
		ft_printf(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (strategy == 3)
		ft_printf(2, "[bench] strategy: Complex / O(n log n)\n");
	else if (strategy == 0)
	{
		if (dorder < 0.2 || len <= 5 )
			ft_printf(2, "[bench] strategy: Adaptive / O(n^2)\n");
		else if (dorder >= 0.2 && dorder < 0.5)
			ft_printf(2, "[bench] strategy: Adaptive / O(n√n)\n");
		else
			ft_printf(2, "[bench] strategy: Adaptive / O(n log n)\n");
	}
	ft_printf(2, "[bench] total_ops: %d\n", b->total_ops);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		b->sa, b->sb, b->ss, b->pa, b->pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}

int	main(int argc, char **args)
{
	t_stack	*stack_a;
	t_bench	*b;
	t_bench	tb;
	int		i;
	double	dorder;

	if (argc == 1)
		return (0);
	ft_bzero(&tb, sizeof(t_bench));
	i = 1;
	stack_a = NULL;
	select_mode(args, &tb, &i);
	if (fill_stack(&stack_a, argc, args, i) == -1)
		return (0);
	dorder = compute_disorder(&stack_a);
	if (tb.is_bench || tb.count_only)
		b = &tb;
	else
		b = NULL;
	select_sort(&stack_a, tb.strategy, dorder, b);
	if (tb.is_bench == 1)
		benchmark(tb.strategy, stack_len(&stack_a), dorder, b);
	if (tb.count_only == 1)
		ft_printf(1, "%d \n", b->total_ops);
	ft_lstclear(&stack_a);
	return (0);
}
