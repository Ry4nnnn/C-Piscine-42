/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:17:04 by ryan              #+#    #+#             */
/*   Updated: 2025/04/28 18:13:01 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	get_word_size(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_charset(str[len], charset))
		len++;
	return (len);
}

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
