/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 23:04:52 by wlim              #+#    #+#             */
/*   Updated: 2025/04/13 13:35:17 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char a);

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

static void	print_row(int x, char left, char mid, char right)
{
	int	col;

	col = 0;
	if (x >= 1)
		ft_putchar(left);
	while (col < x - 2)
	{
		ft_putchar(mid);
		col++;
	}
	if (x > 1)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	row = 0;
	if (x <= 0 || y <= 0)
	{
		ft_putstr("number must be more than 0\n");
		return ;
	}
	while (row < y)
	{
		if (row == 0)
			print_row(x, 'A', 'B', 'A');
		else if (row == y - 1)
			print_row(x, 'C', 'B', 'C');
		else
			print_row(x, 'B', ' ', 'B');
		row++;
	}
}
