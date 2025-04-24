/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:21:09 by wlim              #+#    #+#             */
/*   Updated: 2025/04/17 21:22:53 by wlim             ###   ########.fr       */
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

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	check_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (i < ft_strlen(base))
	{
		j = i;
		while (++j < ft_strlen(base))
			if (base[i] == base[j])
				return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	ft_convert_base(char *nbr, char *base, int *result)
{
	int	base_num;
	int	i;
	int	j;

	base_num = ft_strlen(base);
	i = 0;
	j = 0;
	while (nbr[i])
	{
		while (nbr[i] != base[j] && base[j])
			j++;
		*result = *result * base_num;
		*result = *result + j;
		j = 0;
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
	if (check_valid(base))
	{
		while (is_space(str[i]))
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
	}
	ft_convert_base(str + i, base, &result);
	return (sign * result);
}

/*
#include <stdio.h>
int main()
{
	int i;
	i = ft_atoi_base("101010", "aa");
	printf ("%d\n", i);
	return (0);
}*/
