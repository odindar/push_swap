/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 22:10:51 by iergin            #+#    #+#             */
/*   Updated: 2026/04/24 22:24:24 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if ((nmemb && (size > ((size_t) - 1) / nmemb)))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	d = (char *)ft_calloc((len + 1), sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	d = (char *)ft_calloc((len + 1), sizeof(char));
	if (!d)
		return (NULL);
	i = 0;
	while (i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	return (d);
}

int	split(t_stack **stack_a, char **split_args)
{
	int	j;
	int	num;
	int	err;

	j = 0;
	while (split_args[j])
	{
		err = 0;
		num = strict_atoi(split_args[j], &err);
		if (err || !has_available(*stack_a, num)
			|| !append_node(stack_a, num))
		{
			write(2, "Error\n", 6);
			ft_lstclear(stack_a);
			free_split(split_args);
			return (0);
		}
		j++;
	}
	return (1);
}
