/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:09:41 by iergin            #+#    #+#             */
/*   Updated: 2026/04/18 15:26:43 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a, t_bench *b)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	if (b != NULL)
	{
		b->sa++;
		b->total_ops++;
	}
}

void	sb(t_stack **stack_b, t_bench *b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	if (b != NULL)
	{
		b->sb++;
		b->total_ops++;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	if (b != NULL)
	{
		b->ss++;
		b->total_ops++;
	}
}
