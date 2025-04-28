/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlim <wlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:42:38 by wlim              #+#    #+#             */
/*   Updated: 2025/04/29 00:43:41 by wlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int *ft_map(int *tab, int length, int (*f)(int));

int times_two(int n)
{
    return (n * 2);
}

int main(void)
{
    int tab[] = {1, 2, 3, 4, 5};
    int length = 5;
    int *result;
    int i;

    result = ft_map(tab, length, times_two);
    if (!result)
    {
        printf("Memory allocation failed!\n");
        return (1);
    }

    printf("Original array: ");
    i = 0;
    while (i < length)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
    printf("New array: ");
    i = 0;
    while (i < length)
    {
        printf("%d ", result[i]);
        i++;
    }
    printf("\n");
    free(result);
    return (0);
}
