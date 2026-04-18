/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:44:42 by iergin            #+#    #+#             */
/*   Updated: 2026/04/18 15:26:42 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack_src)
{
	t_stack	*tmp;

	if (!stack_src)
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_src, tmp);
}

void	ra(t_stack **stack_a, t_bench *b)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	if (b != NULL)
	{
		b->ra++;
		b->total_ops++;
	}
}

void	rb(t_stack **stack_b, t_bench *b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	if (b != NULL)
	{
		b->rb++;
		b->total_ops++;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	if (b != NULL)
	{
		b->rr++;
		b->total_ops++;
	}
}
