/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:58:59 by iergin            #+#    #+#             */
/*   Updated: 2026/03/02 11:11:05 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_list **stack_src)
{
	t_list	*last;
	t_list	*second_to_last;

	if (!stack_src)
		return ;
	last = *stack_src;
	second_to_last = NULL;

	while (last->next != NULL) {
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	ft_lstadd_front(stack_src, last);
}
void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 4);
}
