/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:55:29 by iergin            #+#    #+#             */
/*   Updated: 2026/04/12 15:05:07 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h> // SİLİNECEK

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

void	radix_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;
	int		cnt;
	int		cur_stack_a_len;

	i = 0;
	cnt = 0;
	stack_b = NULL;
	assign_index(stack_a);
	while (i < max_idx_bit(stack_len(stack_a) - 1))
	{
		cur_stack_a_len = stack_len(stack_a);
		while (cur_stack_a_len > 0)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a, &cnt);
			else
				pb(stack_a, &stack_b, &cnt);
			cur_stack_a_len--;
		}
		while (stack_b != NULL)
			pa(stack_a, &stack_b, &cnt);
		i++;
	}
	printf("Radix Sort İşlem Sayısı : %d\n", cnt);
}
