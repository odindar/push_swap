/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:50 by iergin            #+#    #+#             */
/*   Updated: 2026/04/13 16:28:19 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_len(t_stack **stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	assign_index(t_stack **stack_a)
{
	t_stack	*num;
	t_stack	*n;
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
