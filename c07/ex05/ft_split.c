/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryan <ryan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:25:22 by ryan              #+#    #+#             */
/*   Updated: 2025/04/22 13:42:01 by ryan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

//this function get the size of the upper array that needs to allocate
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
