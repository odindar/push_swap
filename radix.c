/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:55:29 by iergin            #+#    #+#             */
/*   Updated: 2026/04/24 23:09:10 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_idx_bit(int x)
{
	int	res;

	res = 0;
	while (x != 0)
	{
		x = x >> 1;
		res++;
	}
	return (res);
}

static void	radix(t_stack **stack_a, t_stack **stack_b, t_bench *b, int i)
{
	int		cur_stack_a_len;

	cur_stack_a_len = stack_len(stack_a);
	while (cur_stack_a_len > 0)
	{
		if (((*stack_a)->index >> i) & 1)
			ra(stack_a, b);
		else
			pb(stack_a, stack_b, b);
		cur_stack_a_len--;
	}
}

void	radix_sort(t_stack **stack_a, t_bench *b)
{
	t_stack	*stack_b;
	int		i;
	int		max_bit;

	i = 0;
	stack_b = NULL;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (handle_small_sort(stack_len(stack_a), stack_a, b))
		return ;
	assign_index(stack_a);
	max_bit = max_idx_bit(stack_len(stack_a) - 1);
	while (i < max_bit)
	{
		radix(stack_a, &stack_b, b, i);
		push_b_to_a(stack_a, &stack_b, b);
		i++;
	}
}
