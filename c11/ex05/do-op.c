/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 02:41:27 by wlim              #+#    #+#             */
/*   Updated: 2025/04/29 03:47:04 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_operator(char *op)
{
	char	*operators;
	int		i;

	operators = "+-*/%";
	i = 0;
	if (ft_strlen(op) == 1)
	{
		while (operators[i])
		{
			if (op[0] == operators[i])
				return (1);
			i++;
		}
	}
	return (0);
}

int	calc(int a, int b, int (*op)(int, int))
{
	return (op(a, b));
}

int	ft_do_op(int a, char *op, int b)
{
	int	(*ops[5])(int, int) = {&add, &minus, &multiply, &div, &mod};

	if (!is_operator(op))
		return (0);
	if (op[0] == '+')
		return (calc(a, b, ops[0]));
	if (op[0] == '-')
		return (calc(a, b, ops[1]));
	if (op[0] == '*')
		return (calc(a, b, ops[2]));
	if (op[0] == '/')
		return (calc(a, b, ops[3]));
	if (op[0] == '%')
		return (calc(a, b, ops[4]));
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	if (!ft_strcmp(av[2], "/") && !ft_atoi(av[3]))
	{
		ft_putstr(DIV_ERR);
		return (1);
	}
	else if (!ft_strcmp(av[2], "%") && !ft_atoi(av[3]))
	{
		ft_putstr(MOD_ERR);
		return (1);
	}
	ft_putnbr(ft_do_op(ft_atoi(av[1]), av[2], ft_atoi(av[3])));
	ft_putchar('\n');
}