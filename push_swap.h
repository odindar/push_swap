/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:17 by iergin            #+#    #+#             */
/*   Updated: 2026/03/12 12:51:16 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_list;

// node utils
void	append_node(t_list **stack, int value);

// operations
void	sa(t_list **stack_a, int *cnt);
void	sb(t_list **stack_b, int *cnt);
void	ss(t_list **stack_a, t_list **stack_b, int *cnt);
void	pa(t_list **stack_a, t_list **stack_b, int *cnt);
void	pb(t_list **stack_a, t_list **stack_b, int *cnt);
void	ra(t_list **stack_a, int *cnt);
void	rb(t_list **stack_b, int *cnt);
void	rr(t_list **stack_a, t_list **stack_b, int *cnt);
void	rra(t_list **stack_a, int *cnt);
void	rrb(t_list **stack_b, int *cnt);
void	rrr(t_list **stack_a, t_list **stack_b, int *cnt);

// disorder metric
double	compute_disorder(t_list **stack);

// linked list utils
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstadd_front(t_list **lst, t_list *new_node);
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// libft utils
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//sort utils
int		stack_len(t_list **stack);
int		stack_min(t_list **stack);
int		stack_max(t_list **stack);
void	bubble_sort_array(int *arr, int len);
int		get_median(t_list **stack);
void	assign_index(t_list **stack_a);

void	selection_sort(t_list **stack_a);
void	radix_sort(t_list **stack_a);

//simple
void	min_max_parse(t_list **stack_a, t_list **stack_b, int *cnt);
void	sort_a_to_b(t_list **stack_a, t_list **stack_b, int *cnt);
void	sort_b_to_a(t_list **stack_a, t_list **stack_b, int *cnt);
void	rotate_to_top_a(t_list **stack_a, int i, int *cnt);
void	rotate_to_top_b(t_list **stack_b, int target_idx, int *cnt);

//medium
void	assign_index(t_list **stack_a);
void	k_sort_a_to_b(t_list **stack_a, t_list **stack_b, int *cnt);
void	k_sort(t_list **stack_a);

#endif