/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryan <ryan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:31:38 by ryan              #+#    #+#             */
/*   Updated: 2025/04/21 18:02:24 by ryan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	if (!*range)
	{
		*range = NULL;
		return (-1);
	}
	while (min < max)
	{
		*range[i] = min;
		min++;
		i++;
	}
	return (i);
}
