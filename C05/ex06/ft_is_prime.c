/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:10:39 by wlim              #+#    #+#             */
/*   Updated: 2025/04/20 20:39:20 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//prime number a is number that can only be
//divided by itself and 1
int	ft_is_prime(int nb)
{
	int	div;

	div = 2;
	if (nb <= 1)
		return (0);
	while (div <= nb / 2)
	{
		if (nb % div == 0)
			return (0);
		div++;
	}
	return (1);
}

/*
#include <stdio.h>
int main()
{
	printf ("%d\n", ft_is_prime(5));
	return (0);
}
*/