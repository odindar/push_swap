/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:18:04 by iergin            #+#    #+#             */
/*   Updated: 2026/03/12 14:24:54 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_top_a(t_stack **stack, int i, int *cnt)
{
	int	len;
	int	j;

	len = stack_len(stack);
	if (i <= len / 2)
	{
		while (i > 0)
		{
			ra(stack, cnt);
			i--;
		}
	}
	else
	{
		j = len - i;
		while (j > 0)
		{
			rra(stack, cnt);
			j--;
		}
	}
}

void	rotate_to_top_b(t_stack **stack_b, int target_idx, int *cnt)
{
	int	len;
	int	j;

	len = stack_len(stack_b);
	if (target_idx <= len / 2)
	{
		while (target_idx > 0)
		{
			rb(stack_b, cnt);
			target_idx--;
		}
	}
	else
	{
		j = len - target_idx;
		while (j > 0)
		{
			rrb(stack_b, cnt);
			j--;
		}
	}
}

void	min_max_parse(t_stack **stack_a, t_stack **stack_b, int *cnt)
{
	int	median;
	int	size;
	int	i;

	median = get_median(stack_a);
	size = stack_len(stack_a) / 2;
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->content < median)
		{
			pb(stack_a, stack_b, cnt);
			i++;
		}
		else
			ra(stack_a, cnt);
	}
}

void	sort_a_to_b(t_stack **stack_a, t_stack **stack_b, int *cnt)
{
	int	min_idx;

	while (stack_len(stack_a) > 0)
	{
		min_idx = stack_min(stack_a);
		rotate_to_top_a(stack_a, min_idx, cnt);
		pb(stack_a, stack_b, cnt);
	}
}

void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b, int *cnt)
{
	int	max_idx;

	while (stack_len(stack_b) > 0)
	{
		max_idx = stack_max(stack_b);
		rotate_to_top_b(stack_b, max_idx, cnt);
		pa(stack_a, stack_b, cnt);
	}
}
