/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:21:14 by ryan              #+#    #+#             */
/*   Updated: 2025/04/29 22:00:48 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (!arr)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

/*
#include <stdio.h>
int	main()
{
	int i = 0;
	int a = 5;
	int b = 10;
	int *arr = ft_range(a, b);
	
	while (i < (b - a))
	{
		printf ("%d\n", arr[i]);
		i++;
	}
	free (arr);
	return (0);
}
*/
