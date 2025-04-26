/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:09:51 by wlim              #+#    #+#             */
/*   Updated: 2025/04/26 18:10:15 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

/*
extern		t_stock_str	*ft_strs_to_tab(int ac, char **av);
extern void	ft_show_tab(struct s_stock_str *par);

int	main(int ac, char **av)
{
	t_stock_str	*tab = ft_strs_to_tab(ac - 1, av + 1);
	if (tab)
		ft_show_tab(tab);
	return (0);
}
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;

	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		if (!arr[i].copy)
		{
			while (i > 0)
			{
				free(arr[i - 1].copy);
				i--;
			}
		}
		i++;
	}
	arr[i].str = 0;
	return (arr);
}
