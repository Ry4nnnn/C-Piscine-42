/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:56:55 by wlim              #+#    #+#             */
/*   Updated: 2025/04/15 10:44:59 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	j = 0;
	while (dest[j] != '\0' && j < size)
		j++;
	d_len = j;
	s_len = ft_strlen(src);
	if (size == 0 || size <= d_len)
		return (s_len + size);
	while (src[i] != '\0' && i < size - d_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d_len + s_len);
}

/*
#include <unistd.h>
#include <stdio.h>

int	main()
{
	char src[] = "ABCDEFGHIJKLM";
	char dest[] = "abcdefg";
	unsigned int size = 10;
	printf ("output:\nreturn value: %d\ndest: %s\nappend 
	size: %d\n", ft_strlcat(dest, src, size), dest, size);
	return (0);
}
*/