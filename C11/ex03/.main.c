/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:11:21 by wlim              #+#    #+#             */
/*   Updated: 2025/04/29 03:53:46 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_count_if(char **tab, int length, int (*f)(char *));

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
    int count = ft_count_if(tab, 4, contains_a);

    printf("Number of strings that contains a: %d\n", count);
    return 0;
}
