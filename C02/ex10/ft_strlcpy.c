/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:08:30 by wlim              #+#    #+#             */
/*   Updated: 2025/04/12 17:55:49 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int main ()
{
	char src[] = "";
	char dest[] = "HELLOWORLD";
	size_t num  = 5;
	
	printf ("%d\n", ft_strlcpy(dest, src, num));
	printf ("dest: %s, src: %s\n", dest, src);
	return (0);
}
*/