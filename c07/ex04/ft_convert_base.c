/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 01:29:34 by wlim              #+#    #+#             */
/*   Updated: 2025/04/30 20:59:45 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		check_valid(char *base);
int		ft_atoi_base(char *str, char *base);

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

static void	fill_result(char *res, int nbr, char *base, int len)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	len--;
	while (nbr)
	{
		res[len] = base[nbr % base_len];
		nbr = nbr / base_len;
		len--;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		len;
	int		base_len;
	char	*res;

	base_len = ft_strlen(base);
	len = ft_intlen(nbr, base_len);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nbr == 0)
		res[0] = base[0];
	else
		fill_result(res, nbr, base, len);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	num;

	if (!check_valid(base_from) || !check_valid(base_to))
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(num, base_to));
}
