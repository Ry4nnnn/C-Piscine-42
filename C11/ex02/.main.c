/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:11:25 by wlim              #+#    #+#             */
/*   Updated: 2025/04/29 01:11:26 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_any(char **tab, int (*f)(char *));

int contains_a(char *str)
{
    while (*str)
    {
        if (*str == 'a')
            return 1;
        str++;
    }
    return 0;
}

int main(void)
{
    char *tab[] = {"hello", "world", "apple", "banana", NULL};

    if (ft_any(tab, contains_a))
        printf("At least one string contains 'a'.\n");
    else
        printf("No string contains 'a'.\n");
    return 0;
}
