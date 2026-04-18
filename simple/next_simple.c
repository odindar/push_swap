/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:52:57 by iergin            #+#    #+#             */
/*   Updated: 2026/04/18 15:26:45 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	move_min_to_top(t_stack **stack_a, int len, t_bench *b)
{
	int		j;
	int		min;

	min = stack_min(stack_a);
	if (len / 2 < min)
	{
		j = len - min;
		while (j > 0)
		{
			rra(stack_a, b);
			j--;
		}
	}
	else
	{
		j = min;
		while (j > 0)
		{
			ra(stack_a, b);
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

void	selection_sort(t_stack **stack_a, t_bench *b)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	i = stack_len(stack_a);
	while (i > 2)
	{
		if (is_sorted(*stack_a))
			break ;
		move_min_to_top(stack_a, i, b);
		pb(stack_a, &stack_b, b);
		i--;
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a, b);
	i = stack_len(&stack_b);
	while (i > 0)
	{
		pa(stack_a, &stack_b, b);
		i--;
	}
}
