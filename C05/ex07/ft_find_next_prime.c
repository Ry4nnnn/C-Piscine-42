/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:28:33 by wlim              #+#    #+#             */
/*   Updated: 2025/04/20 22:57:34 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int div, int nb)
{
	if (nb <= 1)
		return (0);
	if ((div * div) > nb)
		return (1);
	if ((nb % div) == 0)
		return (0);
	return (ft_is_prime(div + 1, nb));
}

int	ft_find_next_prime(int nb)
{
	int	div;

	div = 2;
	if (nb <= 1)
		return (2);
	while (!ft_is_prime(div, nb))
		nb++;
	return (nb);
}

/*
#include <stdio.h>
int main()
{
	printf ("%d", ft_find_next_prime(14234783));
	return (0);
}
*/
