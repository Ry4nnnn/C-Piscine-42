/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:49:17 by wlim              #+#    #+#             */
/*   Updated: 2025/04/09 17:49:34 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_print_num(int num)
{
	int	first;
	int	second;

	if (num > 9)
	{
		first = num / 10;
		second = num % 10;
		ft_putchar(first + '0');
		ft_putchar(second + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar(num + '0');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_num(a);
			ft_putchar(' ');
			ft_print_num(b);
			if (a < 98 || b < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
		a++;
	}
}
