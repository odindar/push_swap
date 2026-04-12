/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:15 by iergin            #+#    #+#             */
/*   Updated: 2026/04/12 17:53:05 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_mode(char *arg, int *mode, int *i)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
	{
		*mode = 1;
		*i = 2;
	}
	else if (ft_strncmp(arg, "--medium", 9) == 0)
	{
		*mode = 2;
		*i = 2;
	}
	else if (ft_strncmp(arg, "--complex", 10) == 0)
	{
		*mode = 3;
		*i = 2;
	}
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
	{
		*mode = 0;
		*i = 2;
	}
}

static void	select_sort(t_stack *stack_a, int *mode, double disorder)
{
	if (*mode == 1)
		selection_sort(&stack_a);
	else if (*mode == 2)
		k_sort(&stack_a);
	else if (*mode == 3)
		radix_sort(&stack_a);
	else if (*mode == 0)
	{
		if (disorder != 0 && disorder < 0.2)
			selection_sort(&stack_a);
		else if (disorder >= 0.2 && disorder < 0.5)
			k_sort(&stack_a);
		else if (disorder >= 0.5)
			radix_sort(&stack_a);
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

int	main(int argc, char **args)
{
	t_stack	*stack_a;
	int		i;
	int		mode;
	double	disorder;

	if (argc == 1 || (argc == 2 && !args[1][0]))
		return (0);
	i = 1;
	mode = 0;
	stack_a = NULL;
	if (argc > 1)
		select_mode(args[1], &mode, &i);
	fill_stack(&stack_a, argc, args, i);
	disorder = compute_disorder(&stack_a);
	select_sort(stack_a, &mode, disorder);
	ft_lstclear(&stack_a);
	return (0);
}
