/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:52:57 by iergin            #+#    #+#             */
/*   Updated: 2026/04/12 17:52:57 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"

void	selection_sortt(t_stack **stack_a)
{
	t_stack	*stack_b;
	int	stack_a_min_index;
	int	i;
	int	j;
	int	count;

	stack_b = NULL;
	i = stack_len(stack_a);
	count = 0;
	while (i > 2)
	{
		stack_a_min_index = stack_min(stack_a);
		if (i / 2 < stack_a_min_index)
		{
			j = i - stack_a_min_index;
			while (j > 0)
			{
				rra(stack_a, &count);
				j--;
			}
		}
		else
		{
			j = stack_a_min_index;
			while (j > 0)
			{
				ra(stack_a, &count);
				j--;
			}
		}
		pb(stack_a, &stack_b, &count);
		i--;
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a, &count);
	i = stack_len(&stack_b);
	while (i > 0)
	{
		pa(stack_a, &stack_b, &count);
		i--;
	}
	printf("İşlem sayısı : %d\n", count);
}
