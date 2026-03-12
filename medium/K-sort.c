/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   K-sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:54:05 by iergin            #+#    #+#             */
/*   Updated: 2026/03/12 12:54:13 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h> // SİLİNECEK

void	k_sort_a_to_b(t_list **stack_a, t_list **stack_b, int *cnt)
{
	int	i;
	int	range;

	i = 0;
	range = 15;
	if (stack_len(stack_a) > 100)
		range = 35;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, cnt);
			rb(stack_b, cnt);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b, cnt);
			i++;
		}
		else
			ra(stack_a, cnt);
	}
}

void	k_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		cnt;

	stack_b = NULL;
	cnt = 0;
	assign_index(stack_a);
	k_sort_a_to_b(stack_a, &stack_b, &cnt);
	sort_b_to_a(stack_a, &stack_b, &cnt);
	printf("K-Sort İşlem Sayısı : %d\n", cnt);
}