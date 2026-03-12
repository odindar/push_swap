/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:18:04 by iergin            #+#    #+#             */
/*   Updated: 2026/03/12 14:24:54 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h> // SİLİNECEK

void	selection_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		cnt;

	cnt = 0;
	stack_b = NULL;
	min_max_parse(stack_a, &stack_b, &cnt);
	sort_a_to_b(stack_a, &stack_b, &cnt);
	sort_b_to_a(stack_a, &stack_b, &cnt);
	printf("Selection Sort İşlem Sayısı: %d\n", cnt);
}
