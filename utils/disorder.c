/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:16:59 by iergin            #+#    #+#             */
/*   Updated: 2026/03/12 14:24:54 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	compute_disorder(t_stack **stack)
{
	double	mistakes;
	double	total_pairs;
	t_stack	*cur;
	t_stack	*comp;

	if (!stack || !*stack || !(*stack)->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	cur = *stack;
	while (cur != NULL)
	{
		comp = cur->next;
		while (comp != NULL)
		{
			total_pairs++;
			if ((int)cur->content > (int)comp->content)
				mistakes++;
			comp = comp->next;
		}
		cur = cur->next;
	}
	return (mistakes / total_pairs);
}
