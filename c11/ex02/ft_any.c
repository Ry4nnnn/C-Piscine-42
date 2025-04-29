/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:39:26 by wlim              #+#    #+#             */
/*   Updated: 2025/04/29 18:33:19 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
> (*f)(tab[i])
(dereferencing the pointer before calling the function)
> (f)(tab[i])
(this is a more concise form, but still calls the function correctly)
> f(tab[i])
(the most common and simple way to call a function through a function pointer,
as C automatically dereferences the function pointer for you)
*/
int	ft_any(char **tab, int (*f(char *)))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if ((*f)(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
