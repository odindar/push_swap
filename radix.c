/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:55:29 by iergin            #+#    #+#             */
/*   Updated: 2026/04/23 18:10:12 by iergin           ###   ########.fr       */
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

void	radix_sort(t_stack **stack_a, t_bench *b)
{
	t_stack	*stack_b;
	int		i;
	int		cur_stack_a_len;
	int		len;

	i = 0;
	stack_b = NULL;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	len = stack_len(stack_a);
	if (len == 3)
	{
		sort_three(stack_a, b);
		return ;
	}
	else if (len == 5)
	{
		sort_five(stack_a, b);
		return ;
	}
	assign_index(stack_a);
	while (i < max_idx_bit(stack_len(stack_a) - 1))
	{
		cur_stack_a_len = stack_len(stack_a);
		while (cur_stack_a_len > 0)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a, b);
			else
				pb(stack_a, &stack_b, b);
			cur_stack_a_len--;
		}
		while (stack_b != NULL)
			pa(stack_a, &stack_b, b);
		i++;
	}
}
