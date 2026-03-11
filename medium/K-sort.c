#include "push_swap.h"
#include <stdio.h> // SİLİNECEK

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

void	k_sort_a_to_b(t_list **stack_a, t_list **stack_b, int *cnt)
{
	int	i;
	int	range;

	i = 0;
	range = 15;
	if (stack_len(stack_a) > 100)
		range = 35;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, cnt);
			rb(stack_b, cnt);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b, cnt);
			i++;
		}
		else
			ra(stack_a, cnt);
	}
}

void	k_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		cnt;

	stack_b = NULL;
	cnt = 0;
	assign_index(stack_a);
	k_sort_a_to_b(stack_a, &stack_b, &cnt);
	sort_b_to_a(stack_a, &stack_b, &cnt);
	printf("K-Sort İşlem Sayısı : %d\n", cnt);
}