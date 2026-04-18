/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:29:11 by iergin            #+#    #+#             */
/*   Updated: 2026/04/18 15:26:40 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (!stack_src)
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_dst, tmp);
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	if (b != NULL)
	{
		b->pa++;
		b->total_ops++;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	if (b != NULL)
	{
		b->pb++;
		b->total_ops++;
	}
}
