/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:28:17 by iergin            #+#    #+#             */
/*   Updated: 2026/04/18 15:27:08 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_bench
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total_ops;
}	t_bench;
// node utils
int		append_node(t_stack **stack, int value);
int		has_available(t_stack *stack, int content);

// operations
void	sa(t_stack **stack_a, t_bench *b);
void	sb(t_stack **stack_b, t_bench *b);
void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *b);
void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *b);
void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *b);
void	ra(t_stack **stack_a, t_bench *b);
void	rb(t_stack **stack_b, t_bench *b);
void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *b);
void	rra(t_stack **stack_a, t_bench *b);
void	rrb(t_stack **stack_b, t_bench *b);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *b);

// disorder metric
double	compute_disorder(t_stack **stack);

// linked list utils
void	ft_lstadd_back(t_stack **lst, t_stack *new_node);
void	ft_lstadd_front(t_stack **lst, t_stack *new_node);
void	ft_lstclear(t_stack **lst);

// libft utils
int		simple_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);

//sort utils
int		stack_len(t_stack **stack);
int		stack_min(t_stack **stack);
int		stack_max(t_stack **stack);
void	bubble_sort_array(int *arr, int len);
int		get_median(t_stack **stack);
void	assign_index(t_stack **stack_a);

// sorts
void	selection_sort(t_stack **stack_a, t_bench *b);
void	k_sort(t_stack **stack_a, t_bench *b);
void	radix_sort(t_stack **stack_a, t_bench *b);

#endif
