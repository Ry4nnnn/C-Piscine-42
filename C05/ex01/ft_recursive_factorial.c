/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:09:22 by wlim              #+#    #+#             */
/*   Updated: 2025/04/17 20:13:00 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// visualize recursion
// ft_recursive_factorial(5)
// = 5 * ft_recursive_factorial(4)
// = 5 * (4 * ft_recursive_factorial(3))
// = 5 * (4 * (3 * ft_recursive_factorial(2)))
// = 5 * (4 * (3 * (2 * ft_recursive_factorial(1))))
// = 5 * (4 * (3 * (2 * 1)))
// = 5 * 4 * 3 * 2 * 1
// = 120