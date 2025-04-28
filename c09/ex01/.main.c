#include "ft.h"
#include <stdio.h> // for printf to show results

int main(void)
{
    // Test ft_putchar
    ft_putchar('A');
    ft_putchar('\n');

    // Test ft_putstr
    ft_putstr("Testing ft_putstr: Hello, Ryan!\n");

    // Test ft_strlen
    char *str = "Hello, World!";
    int length = ft_strlen(str);
    printf("Testing ft_strlen: Length of '%s' is %d\n", str, length);

    // Test ft_strcmp
    char *s1 = "abc";
    char *s2 = "abc";
    char *s3 = "abcd";
    printf("Testing ft_strcmp: 'abc' vs 'abc' => %d\n", ft_strcmp(s1, s2));
    printf("Testing ft_strcmp: 'abc' vs 'abcd' => %d\n", ft_strcmp(s1, s3));
    printf("Testing ft_strcmp: 'abcd' vs 'abc' => %d\n", ft_strcmp(s3, s1));

    // Test ft_swap
    int a = 42;
    int b = 24;
    printf("Before ft_swap: a = %d, b = %d\n", a, b);
    ft_swap(&a, &b);
    printf("After ft_swap: a = %d, b = %d\n", a, b);

    return 0;
}
