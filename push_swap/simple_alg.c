/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:18:04 by iergin            #+#    #+#             */
/*   Updated: 2026/03/04 15:58:09 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // KALDIR

void	selection_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int	stack_a_min_index;
	int	i;
	int	j;
	int	count = 0; // deneme için kaldırılacak

	stack_b = NULL;
	i = stack_len(stack_a);
	stack_a_min_index = stack_min(stack_a);
	while (i > 2)
	{
		if (i / 2 < stack_a_min_index) // altta
		{
			j = i - stack_a_min_index;
			while (j > 0)
			{
				rra(stack_a);
				count++;
				j--;
			}
		}
		else
		{
			j = stack_a_min_index;
			while (j > 0)
			{
				ra(stack_a);
				count++;
				j--;
			}
		}
		pb(stack_a, &stack_b);
		count++;
		stack_a_min_index = stack_min(stack_a);
		i--;
	}
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		sa(stack_a);
		count++;
	}
	i = stack_len(&stack_b);
	while (i > 0)
	{
		pa(stack_a, &stack_b);
		count++;
		i--;
	}
	printf("İşlem sayısı : %d\n", count);
}
