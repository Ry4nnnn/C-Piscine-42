/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:25:22 by ryan              #+#    #+#             */
/*   Updated: 2025/04/24 23:46:29 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Checks if a character exists in the charset.
 * 
 * @param c Character to check.
 * @param charset String containing separator characters.
 * @return int 1 if character is found in charset, otherwise 0.
 */
int	is_set(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

/**
 * @brief Calculates the number of substrings that will be created from the input string,
 *        based on the given separators.
 * 
 * @param str The input string to be split.
 * @param charset String containing separator characters.
 * @return int Number of substrings that will be allocated in the split.
 */
int	get_len(char *str, char *charset)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_set(str[i], charset))
			i++;
		if (str[i] != '\0' && !is_set(str[i], charset))
		{
			len++;
			while (str[i] != '\0' && !is_set(str[i], charset))
				i++;
		}
		i++;
	}
	return (len);
}

/**
 * @brief Calculates the length of the current word (substring) until a separator is found.
 * 
 * @param str Current position in the input string.
 * @param charset String containing separator characters.
 * @return int Length of the word until the next separator.
 */
int	get_inner_len(char *str, char *charset)
{
	int len;

	len = 0;
	while (str[len] && !is_set(str[len], charset))
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while ((i < size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/**
 * @brief purpose of this function is to split the given single array (str)
 * into a 2d array separated by the contents in the array charset
 * 
 * @param str given string to be seperated
 * @param charset separators
 * @return the malloc-ed 2d array
 */
char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		inner_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (get_len(str, charset) + 1));
	if (!res)
		return (NULL);
	while (str[i] != '\0' && j < get_len(str , charset))
	{
		while (str[i] != '\0' && is_set(str[i], charset))
			i++;
		inner_len = get_inner_len(&str[i], charset);
		res[j] = malloc(sizeof(char) * (inner_len + 1));
		if (!res[j])
			return (NULL);
		ft_strlcpy(res[j], &str[i], inner_len + 1);
		i = i + inner_len;
		j++;
	}
	res[j] = NULL;
	return (res);
}

#include <stdio.h>
int main()
{
	char str[] = "";
	char charset[] = "";
	char **res;
	int i  = 0;
	res = ft_split(str, charset);
	while (res[i] != NULL)
	{
		printf ("%s\n", res[i]);
		i++;
	}
	return (0);
}
