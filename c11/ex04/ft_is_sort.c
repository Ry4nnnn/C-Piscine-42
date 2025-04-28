/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:27:07 by wlim              #+#    #+#             */
/*   Updated: 2025/04/29 02:07:56 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	order;

	i = 1;
	order = 0;
	if (length <= 1)
		return (1);
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
		{
			if (order == 1)
				return (0);
			order = -1;
		}
		else if (f(tab[i - 1], tab[i]) < 0)
		{
			if (order == -1)
				return (0);
			order = 1;
		}
		i++;
	}
	return (1);
}
