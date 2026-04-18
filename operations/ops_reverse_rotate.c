/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:58:59 by iergin            #+#    #+#             */
/*   Updated: 2026/04/18 15:26:41 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate(t_stack **stack_src)
{
	t_stack	*last;
	t_stack	*second_to_last;

	if (!stack_src)
		return ;
	last = *stack_src;
	second_to_last = NULL;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	ft_lstadd_front(stack_src, last);
}

void	rra(t_stack **stack_a, t_bench *b)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
	if (b != NULL)
	{
		b->rra++;
		b->total_ops++;
	}
}

void	rrb(t_stack **stack_b, t_bench *b)
{
	rrotate(stack_b);
	write(1, "rrb\n", 4);
	if (b != NULL)
	{
		b->rrb++;
		b->total_ops++;
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 4);
	if (b != NULL)
	{
		b->rrr++;
		b->total_ops++;
	}
}
