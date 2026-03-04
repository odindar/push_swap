/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:59:50 by iergin            #+#    #+#             */
/*   Updated: 2026/03/04 15:34:00 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_list **stack)
{
	int	len;
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
	t_list *tmp;
	int	min;
	int	i;
	int	index;

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
