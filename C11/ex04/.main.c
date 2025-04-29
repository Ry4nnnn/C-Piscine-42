#include <stdio.h>

int ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_intcmp(int a, int b)
{
	if (a < b)
		return (-1);
	else if (a > b)
		return (1);
	else
		return (0);
}

int main(void)
{
	int arr[] = {6, 5, 3, 2, 1};
	int length = 5;
	printf("sorted? %d\n", ft_is_sort(arr, length, ft_intcmp));
	return 0;
}
