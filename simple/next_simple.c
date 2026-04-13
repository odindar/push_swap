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

static	void	move_min_to_top(t_stack **stack_a, int min_idx, int len, int *count)
{	
	int		j;

	if (len / 2 < min_idx)
	{
		j = len - min_idx;
		while (j > 0)
		{
			rra(stack_a, count);
			j--;
		}
	}
	else
	{
		j = min_idx;
		while (j > 0)
		{
			ra(stack_a, count);
			j--;
		}
	}
}

static	int	is_sorted(t_stack *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	selection_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;
	int		count;

	stack_b = NULL;
	count = 0;
	i = stack_len(stack_a);
	while (i > 2)
	{
		if (is_sorted(*stack_a))
			break ;
		move_min_to_top(stack_a, stack_min(stack_a), i, &count);
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
