/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:55:29 by iergin            #+#    #+#             */
/*   Updated: 2026/04/17 16:44:25 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	radix_sort(t_stack **stack_a, t_bench *bench)
{
	t_stack	*stack_b;
	int		i;
	int		cur_stack_a_len;

	i = 0;
	stack_b = NULL;
	assign_index(stack_a);
	while (i < max_idx_bit(stack_len(stack_a) - 1))
	{
		cur_stack_a_len = stack_len(stack_a);
		while (cur_stack_a_len > 0)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a, bench);
			else
				pb(stack_a, &stack_b, bench);
			cur_stack_a_len--;
		}
		while (stack_b != NULL)
			pa(stack_a, &stack_b, bench);
		i++;
	}
}
