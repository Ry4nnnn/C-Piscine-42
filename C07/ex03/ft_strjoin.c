/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:01:06 by wlim              #+#    #+#             */
/*   Updated: 2025/05/01 18:08:00 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/**
 * @brief this function with iterate though the given array
 * and count the number of characters
 * @return length of the given array
 */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief this function will iterate through the 2d array (strs)
 * and get the length of it + the length of separators multiply
 * by size - 1
 * @return length of 2d array + (length of sep * (size - 1))
 */
int	get_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		total_len += ft_strlen(sep) * (size - 1);
	return (total_len);
}

/**
 * @brief this functions joins multiple string in strs into a single string
 * adding sep (separator) between each string
 * @param size represents how many strings to join from strs
 * @param strs is an array of arrays (2d) waiting for be contatenate
 * @param sep is the separator needed to be inserted between strings in strs
 * @return an allocated string that is separated by sep
 */
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		j;
	int		nindex;

	i = 0;
	nindex = 0;
	if (size == 0)
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	res = malloc(get_total_len(size, strs, sep) + 1);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			res[nindex++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			res[nindex++] = sep[j++];
		i++;
	}
	res[nindex] = 0;
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	// char	*tab[3];
	// tab[0] = "HELLO";
	// tab[1] = "WORLD";
	// tab[2] = "WELCO";
	char *tab[] = {"HELLO", "WORLD", "WELCO"};
	char sep[] = "-=-";
	printf("%s\n", ft_strjoin(3, tab, sep));
	return (0); 
}
*/