/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryan <ryan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:09:43 by ryan              #+#    #+#             */
/*   Updated: 2025/04/21 12:57:05 by ryan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	char *res;
	int	i;

	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i] != '\0')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*
#include <stdio.h>
int main()
{
	char src[] = "Hello World";
	char *res = ft_strdup(src);
	printf ("%s\n", res);
	free (res);
	return (0);
}
*/