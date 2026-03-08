/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 21:55:29 by iergin            #+#    #+#             */
/*   Updated: 2026/03/08 23:19:15 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	max_idx_bit (int x)
{
	int	res;
	
	res = 0;
	while (x != 0)
	{
		x = x >> 1;
		res++;
	}
	return (res);
}

static void	assign_idx(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*min_node;
	int	len;
	int	i;
	
	i = 0;
	len = stack_len(stack_a);
	while (i < len)
	{
		tmp = *stack_a;
		min_node = NULL;
		while (tmp != NULL)
		{
			if (tmp->index == -1)
			{
				if (min_node == NULL || tmp->content < min_node->content)
					min_node = tmp;
			}
			tmp = tmp->next;
		}
		if (min_node != NULL)
			min_node->index = i;
		i++;
	}
}

void	radix_sort(t_list **stack_a)
{
	int	max_idx;
	t_list *stack_b;
	int	i;
	int	cur_stack_a_len;
	
	i = 0;
	stack_b = NULL;
	assign_idx(stack_a);
	max_idx = max_idx_bit(stack_len(stack_a) - 1);
	while (i < max_idx)
	{
		cur_stack_a_len = stack_len(stack_a);
		while (cur_stack_a_len > 0)
		{
			if ((((*stack_a)->index >> i) & 1))
				ra(stack_a);
			else
				pb(stack_a, &stack_b);
			cur_stack_a_len--;
		}
		while (stack_b != NULL) {
			pa(stack_a, &stack_b);
		}
		i++;
	}
}
