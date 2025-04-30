/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:31:38 by ryan              #+#    #+#             */
/*   Updated: 2025/04/30 21:57:46 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

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
