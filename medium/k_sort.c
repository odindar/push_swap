/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:54:05 by iergin            #+#    #+#             */
/*   Updated: 2026/03/29 16:39:30 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h> // SİLİNECEK

static	void	k_sort_a_to_b(t_stack **stack_a, t_stack **stack_b, int *cnt)
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

static	void	rotate_to_top_b(t_stack **stack_b, int target_idx, int *cnt)
{
	int	len;
	int	j;

	len = stack_len(stack_b);
	if (target_idx <= len / 2)
	{
		while (target_idx > 0)
		{
			rb(stack_b, cnt);
			target_idx--;
		}
	}
	else
	{
		j = len - target_idx;
		while (j > 0)
		{
			rrb(stack_b, cnt);
			j--;
		}
	}
}

static	void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b, int *cnt)
{
	int	max_idx;

	while (stack_len(stack_b) > 0)
	{
		max_idx = stack_max(stack_b);
		rotate_to_top_b(stack_b, max_idx, cnt);
		pa(stack_a, stack_b, cnt);
	}
}

void	k_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		cnt;

	stack_b = NULL;
	cnt = 0;
	assign_index(stack_a);
	k_sort_a_to_b(stack_a, &stack_b, &cnt);
	sort_b_to_a(stack_a, &stack_b, &cnt);
	printf("K-Sort İşlem Sayısı : %d\n", cnt);
}
