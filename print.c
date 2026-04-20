/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iergin <iergin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:54:05 by iergin            #+#    #+#             */
/*   Updated: 2026/04/19 17:33:08 by iergin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		i++;
	write(fd, s, i);
}

static  void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	write(fd, &c, 1);
}

static  void	print_disorder_fd(double n, int fd)
{
	int		total;
	int		f;
	char	c;

	total = (int)(n * 100 + 0.5); 
	ft_putnbr_fd(total / 100, fd);
	write(fd, ".", 1);
	f = total % 100;
	c = (f / 10) + '0';
	write(fd, &c, 1);
	c = (f % 10) + '0';
	write(fd, &c, 1);
}

void	ft_printf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			if (format[i] == 's')
				ft_putstr_fd(va_arg(args, char *), fd);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putnbr_fd(va_arg(args, int), fd);
			else if (format[i] == 'f')
				print_disorder_fd(va_arg(args, double), fd);
			else if (format[i] == '%')
				write(fd, "%", 1);
		}
		else
			write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
}
