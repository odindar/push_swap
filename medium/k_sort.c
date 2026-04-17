/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:54:05 by iergin            #+#    #+#             */
/*   Updated: 2026/04/17 16:44:48 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	k_sort_a_to_b(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	i;
	int	range;

	i = 0;
	range = 15;
	if (stack_len(stack_a) > 100)
		range = 35;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, bench);
			rb(stack_b, bench);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b, bench);
			i++;
		}
		else
			ra(stack_a, bench);
	}
}

static	void	rotate_to_top_b(t_stack **stack_b, int target_idx, t_bench *bench)
{
	int	len;
	int	j;

	len = stack_len(stack_b);
	if (target_idx <= len / 2)
	{
		while (target_idx > 0)
		{
			rb(stack_b, bench);
			target_idx--;
		}
	}
	else
	{
		j = len - target_idx;
		while (j > 0)
		{
			rrb(stack_b, bench);
			j--;
		}
	}
}

static	void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	max_idx;

	while (stack_len(stack_b) > 0)
	{
		max_idx = stack_max(stack_b);
		rotate_to_top_b(stack_b, max_idx, bench);
		pa(stack_a, stack_b, bench);
	}
}

void	k_sort(t_stack **stack_a, t_bench *bench)
{
	t_stack	*stack_b;

	stack_b = NULL;
	assign_index(stack_a);
	k_sort_a_to_b(stack_a, &stack_b, bench);
	sort_b_to_a(stack_a, &stack_b, bench);
}
