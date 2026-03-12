/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:50 by iergin            #+#    #+#             */
/*   Updated: 2026/03/12 12:50:43 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_len(t_list **stack)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	stack_min(t_list **stack)
{
	t_list	*tmp;
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

int	stack_max(t_list **stack)
{
	t_list	*tmp;
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

int	get_median(t_list **stack)
{
	t_list	*tmp;
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

void	assign_index(t_list **stack_a)
{
	t_list	*num;
	t_list	*n;
	int		i;

	num = *stack_a;
	while (num)
	{
		i = 0;
		n = *stack_a;
		while (n)
		{
			if (n->content < num->content)
				i++;
			n = n->next;
		}
		num->index = i;
		num = num->next;
	}
}
