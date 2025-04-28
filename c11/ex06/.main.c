#include <stdio.h>

void ft_sort_string_tab(char **tab);

int main(void)
{
	char *tab[] = {"banana", "apple", "pear", "orange", NULL};
	int i = 0;

	ft_sort_string_tab(tab);

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return 0;
}
