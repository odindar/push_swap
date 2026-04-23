/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:45:55 by iergin            #+#    #+#             */
/*   Updated: 2026/04/23 18:46:37 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_position(t_stack *stack, int target_value)
{
	int pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == target_value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

void	sort_three(t_stack **stack_a, t_bench *b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	assign_index(stack_a);
	if ((*stack_a)->index == 2)
		ra(stack_a, b);
	else if ((*stack_a)->next->index == 2)
		rra(stack_a, b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, b);
}

void	sort_five(t_stack **stack_a, t_bench *b)
{
	t_stack	*stack_b;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	stack_b = NULL;
	move_min_to_top(stack_a, 5, b);
	pb(stack_a, &stack_b, b);
	move_min_to_top(stack_a, 4, b);
	pb(stack_a, &stack_b, b);
	sort_three(stack_a, b);
	pa(stack_a, &stack_b, b);
	pa(stack_a, &stack_b, b);
}
