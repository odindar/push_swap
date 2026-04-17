/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:44:42 by iergin            #+#    #+#             */
/*   Updated: 2026/04/17 16:59:57 by iergin           ###   ########.fr       */
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

void	ra(t_stack **stack_a, t_bench *bench)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	if(bench != NULL)
	{
		bench->ra++;
		bench->total_ops++;
	}
}

void	rb(t_stack **stack_b, t_bench *bench)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	if(bench != NULL)
	{
		bench->rb++;
		bench->total_ops++;
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	if(bench != NULL)
	{
		bench->rr++;
		bench->total_ops++;
	}
}
