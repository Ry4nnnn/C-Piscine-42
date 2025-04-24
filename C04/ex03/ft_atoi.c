/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:55:50 by wlim              #+#    #+#             */
/*   Updated: 2025/04/17 19:56:58 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 59)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <unistd.h>
int main()
{
	char str[] = " ---+--+1234ab567";
	printf ("%d\n", ft_atoi(str));
	return(0);
}
*/