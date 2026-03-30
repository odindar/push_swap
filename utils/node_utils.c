/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:35:48 by iergin            #+#    #+#             */
/*   Updated: 2026/03/30 11:40:34 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_node(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = -1;
	return (new_node);
}

int	append_node(t_stack **stack, int content)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = create_node(content);
	if (!new_node)
	{
		ft_lstclear(stack);
		return (0);
	}
	if (*stack == NULL)
	{
		*stack = new_node;
		return (1);
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	return (1);
}

int	has_available(t_stack *stack, int content)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->content == content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
