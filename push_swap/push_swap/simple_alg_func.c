/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:18:04 by iergin            #+#    #+#             */
/*   Updated: 2026/03/05 13:09:09 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_to_top_a(t_list **stack, int i)
{
	int len;
	int j;  

	len = stack_len(stack);
	if (i <= len / 2)
	{
		while (i > 0)
		{
			ra(stack);
			i--;
		}
	}
	else
	{
		j = len - i;
		while (j > 0)
		{
			rra(stack);
			j--;
		}
	}
}

void rotate_to_top_b(t_list **stack_b, int target_idx)
{
	int len;
	int j;

	len = stack_len(stack_b);
	if (target_idx <= len / 2)
	{
		while (target_idx > 0)
		{
			rb(stack_b);
			target_idx--;
		}
	}
	else
	{
		j = len - target_idx;
		while (j > 0)
		{
			rrb(stack_b);
			j--;
		}
	}
}

void min_max_parse(t_list **stack_a, t_list **stack_b)
{
	int median;
	int size;
	int i;

	median = get_median(stack_a);
	size = stack_len(stack_a) / 2;
	i = 0;

	while (i < size)
	{
		if ((*stack_a)->content < median)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void sort_a_to_b(t_list **stack_a, t_list **stack_b)
{
	int min_idx;

	while (stack_len(stack_a) > 0)
	{
		min_idx = stack_min(stack_a);
		rotate_to_top_a(stack_a, min_idx);
		pb(stack_a, stack_b);
	}
}

void sort_b_to_a(t_list **stack_a, t_list **stack_b)
{
	int max_idx;

	while (stack_len(stack_b) > 0)
	{
		max_idx = stack_max(stack_b);
		rotate_to_top_b(stack_b, max_idx);
		pa(stack_a, stack_b);
	}
}