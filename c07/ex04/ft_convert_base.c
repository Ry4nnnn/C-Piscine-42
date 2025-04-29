/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:29:34 by wlim              #+#    #+#             */
/*   Updated: 2025/04/30 03:34:28 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);
int		check_valid(char *base);

static int	ft_intlen(int nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int nbr, char *base_to)
{
	int		base_len;
	int		len;
	char	*res;

	base_len = ft_strlen(base_to);
	len = ft_intlen(nbr, base_len);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr == 0)
		res[0] = base_to[0];
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		res[len - 1] = base_to[nbr % base_len];
		nbr = nbr / base_len;
		len--;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	num;

	if (ft_strlen(base_from) <= 1 || ft_strlen(base_to) <= 1)
		return (NULL);
	if (!check_valid(base_from) || !check_valid(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(num, base_to));
}
