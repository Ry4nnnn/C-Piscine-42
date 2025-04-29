/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:17:04 by ryan              #+#    #+#             */
/*   Updated: 2025/04/29 22:07:10 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Checks if a character exists within a set of separator characters.
 * 
 * @param c Character to check.
 * @param charset String containing separator characters.
 * @return int 1 if character is found in charset, otherwise 0.
 */
int	is_charset(char c, char *charset)
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
 * @brief Calculates the number of substrings
 * 
 * @param str The input string to be split.
 * @param charset String containing separator characters.
 * @return int Number of substrings to be allocated.
 */
int	get_size(char *str, char *charset)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i] != '\0' && !is_charset(str[i], charset))
		{
			len++;
			while (str[i] && !is_charset(str[i], charset))
				i++;
		}
	}
	return (len);
}

/**
 * @brief Calculates the length of a word (substring)
 * from the current position until a separator is found.
 * 
 * @param str Current position in the input string.
 * @param charset String containing separator characters.
 * @return int Length of the word.
 */
int	get_word_size(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_charset(str[len], charset))
		len++;
	return (len);
}

/**
 * @brief Copies a word from the input string
 * up to the next separator into a newly allocated string.
 * 
 * @param str Current position in the input string.
 * @param charset String containing separator characters.
 * @return char* Pointer to the newly allocated word string.
 */
char	*copy_word(char *str, char *charset)
{
	int		len;
	char	*word;
	int		i;

	len = get_word_size(str, charset);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/**
 * @brief Splits a given string into an array of substrings
 * based on specified separator characters.
 * 
 * @param str The string to split.
 * @param charset String containing separator characters.
 * @return char** an allocated NULL-terminated array of strings (2d array).
 */
char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * (get_size(str, charset) + 1));
	if (!res)
		return (NULL);
	while (str[i] && j < get_size(str, charset))
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		res[j] = copy_word(&str[i], charset);
		if (!res[j])
			return (NULL);
		i = i + get_word_size(&str[i], charset);
		j++;
	}
	res[j] = NULL;
	return (res);
}
