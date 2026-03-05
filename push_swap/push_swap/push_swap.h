/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:17 by iergin            #+#    #+#             */
/*   Updated: 2026/03/05 13:08:36 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_list;

// node utils
void	append_node(t_list **stack, int value);

// operations
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a,t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// disorder metric
double	compute_disorder(t_list **stack);

// linked list utils
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// libft utils
int	ft_atoi(const char *str);

//sort utils
int	stack_len(t_list **stack);
int	stack_min(t_list **stack);
int	stack_max(t_list **stack);
void bubble_sort_array(int *arr, int len);
int get_median(t_list **stack);

void	selection_sort(t_list **stack_a);

//simple
void min_max_parse(t_list **stack_a, t_list **stack_b);
void sort_a_to_b(t_list **stack_a, t_list **stack_b);
void sort_b_to_a(t_list **stack_a, t_list **stack_b);
void rotate_to_top_a(t_list **stack_a, int i);
void rotate_to_top_b(t_list **stack_b, int target_idx);

void simple(t_list **stack_a);

#endif
