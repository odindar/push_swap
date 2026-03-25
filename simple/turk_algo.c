/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:22:26 by iergin            #+#    #+#             */
/*   Updated: 2026/03/12 15:03:20 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *get_max_node(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max_node;
	int		max;

	if (!stack)
		return (NULL);
	tmp = stack;
	max = tmp->content;
	max_node = tmp;
	while (tmp != NULL)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node);
}
void	target_nodes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_stack_a;
	t_stack	*tmp_stack_b;
	t_stack	*target_node;
	int		best_match;

	tmp_stack_a = *stack_a;
	while (tmp_stack_a != NULL) {
		tmp_stack_b = *stack_b;
		best_match = -2147483648;
		while (tmp_stack_b != NULL) {
			if ((tmp_stack_b->content < tmp_stack_a->content) 
				&& tmp_stack_b->content > best_match)
			{
				best_match = tmp_stack_b->content;
				target_node = tmp_stack_b;
			}
			tmp_stack_b = tmp_stack_b->next;
		}
		if (best_match == -2147483648)
			target_node = get_max_node(*stack_b);
		tmp_stack_a->target = target_node;
		tmp_stack_a = tmp_stack_a->next;
	}
}
void	turk_algo(t_stack **stack_a)
{
	t_stack	*stack_b;
	int cnt;
	
	cnt = 0;
	stack_b = NULL;
	pb(stack_a, &stack_b, &cnt);
	pb(stack_a, &stack_b, &cnt);
	target_nodes(stack_a, &stack_b);
}
