/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:48:42 by wlim              #+#    #+#             */
/*   Updated: 2025/04/15 09:56:13 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0' && str[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	main()
{
	char str[] = "Hello world";
	char to_find[] = "wors";
	int i = 0;
	char *expected = strstr(str, to_find);
	char *output = ft_strstr(str, to_find);
	
	printf ("expected: %s\n", strstr(str, to_find));
	printf ("output: %s\n", ft_strstr(str, to_find));
	return (0);
}
*/
