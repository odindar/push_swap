/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:54:05 by iergin            #+#    #+#             */
/*   Updated: 2026/04/18 16:18:33 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	k_sort_a_to_b(t_stack **stack_a, t_stack **stack_b, t_bench *b)
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
			pb(stack_a, stack_b, b);
			rb(stack_b, b);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b, b);
			i++;
		}
		else
			ra(stack_a, b);
	}
}

static	void	rotate_to_top_b(t_stack **stack_b, int target_idx, t_bench *b)
{
	int	len;
	int	j;

	len = stack_len(stack_b);
	if (target_idx <= len / 2)
	{
		while (target_idx > 0)
		{
			rb(stack_b, b);
			target_idx--;
		}
	}
	else
	{
		j = len - target_idx;
		while (j > 0)
		{
			rrb(stack_b, b);
			j--;
		}
	}
}

static	void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b, t_bench *b)
{
	int	max_idx;

	while (stack_len(stack_b) > 0)
	{
		max_idx = stack_max(stack_b);
		rotate_to_top_b(stack_b, max_idx, b);
		pa(stack_a, stack_b, b);
	}
}

void	k_sort(t_stack **stack_a, t_bench *b)
{
	t_stack	*stack_b;

	stack_b = NULL;
	assign_index(stack_a);
	k_sort_a_to_b(stack_a, &stack_b, b);
	sort_b_to_a(stack_a, &stack_b, b);
}
