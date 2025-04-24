/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:39:11 by wlim              #+#    #+#             */
/*   Updated: 2025/04/19 00:39:14 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

// 2 * ft_recursive_power(2, 2)
// 2 * 2 * ft_recursive_power(2, 1)
// 2 * 2 * 2 * ft_recursive_power(2, 0)
// 2 * 2 * 2 * 1 = 8