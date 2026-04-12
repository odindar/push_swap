/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:11:22 by iergin            #+#    #+#             */
/*   Updated: 2026/04/12 15:11:48 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_min(t_stack **stack)
{
	t_stack	*tmp;
	int		min;
	int		i;
	int		index;

	if (!(*stack))
		return (0);
	tmp = *stack;
	min = tmp->content;
	i = 0;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

int	stack_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		i;
	int		index;

	if (!(*stack))
		return (0);
	tmp = *stack;
	max = tmp->content;
	i = 0;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp->content > max)
		{
			max = tmp->content;
			index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (index);
}

void	bubble_sort_array(int *arr, int len)
{
	int	i;
	int	tmp;

	while (len > 0)
	{
		i = 0;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
		len--;
	}
}

int	get_median(t_stack **stack)
{
	t_stack	*tmp;
	int		*arr;
	int		len;
	int		i;
	int		median;

	len = stack_len(stack);
	arr = (int *)malloc(sizeof(int) * len);
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	bubble_sort_array(arr, len);
	median = arr[len / 2];
	free(arr);
	return (median);
}
