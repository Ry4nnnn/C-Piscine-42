/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:21:09 by wlim              #+#    #+#             */
/*   Updated: 2025/04/29 22:26:37 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_valid(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(base);
	if (len < 2)
		return (0);
	while (i < len)
	{
		j = i;
		while (++j < len)
			if (base[i] == base[j])
				return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

//this function will return -1 if number is not in base
int	index_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_convert_base(char *nbr, char *base, int *result)
{
	int	i;
	int	index;
	int	base_num;

	i = 0;
	index = 0;
	base_num = ft_strlen(base);
	while (nbr[i])
	{
		index = index_in_base(nbr[i], base);
		if (index == -1)
			break ;
		*result = *result * base_num + index;
		i++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	if (!check_valid(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	ft_convert_base(str + i, base, &result);
	return (sign * result);
}

/* 
#include <stdio.h>
int main()
{
	int i;
	i = ft_atoi_base("--101010", "01");
	printf ("%d\n", i);
	return (0);
} */