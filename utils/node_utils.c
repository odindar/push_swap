/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:35:48 by iergin            #+#    #+#             */
/*   Updated: 2026/03/08 22:14:55 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_node(int content)
{
	t_list  *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = -1;
	return (new_node);
}

void	append_node(t_list **stack, int content)
{
	t_list  *new_node;
	t_list  *last;

	new_node = create_node(content);
	if (!new_node)
		return ; // Gerçek projede burada belleği temizleyip (free) çıkmalısın.

	if (*stack == NULL) // Eğer stack boşsa, ilk eleman yeni düğüm olur
	{
		*stack = new_node;
		return ;
	}

	last = *stack;
	while (last->next != NULL) // Listenin sonunu bul
		last = last->next;

	last->next = new_node;     // Son elemanın next'ini yeni düğüme bağla
	new_node->prev = last;     // Yeni düğümün prev'ini eski son elemana bağla
}
