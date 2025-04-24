/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:10:22 by wlim              #+#    #+#             */
/*   Updated: 2025/04/12 17:55:37 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//converts upper to lower case
char	ft_tolower(char alpha)
{
	if (alpha >= 65 && alpha <= 90)
		alpha += 32;
	return (alpha);
}

//converts lower to upper case
char	ft_toupper(char alpha)
{
	if (alpha >= 97 && alpha <= 122)
		alpha -= 32;
	return (alpha);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
		else if ((str[i - 1] >= 65 && str[i - 1] <= 90)
			|| (str[i - 1] >= 97 && str[i - 1] <= 122)
			|| (str[i - 1] >= 48 && str[i - 1] <= 57))
		{
			str[i] = ft_tolower(str[i]);
			i++;
		}
		else
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (str);
}

/*
#include <stdio.h>
int main()
{
	char str[] = "hi, how are you? 42words forty-two; fifty+and+one";

	char *res = ft_strcapitalize(str);
	printf ("%s\n", res);
	return (0);
}
*/