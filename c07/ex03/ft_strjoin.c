#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

//this func gets the length of the string in every array
// + the length of the (seperators * size - 1)
int	get_total_len(int size, char **strs, char *sep)
{
	int total_len;
	int i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		total_len += ft_strlen(sep) + (size - 1);
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *res;
	int i;
	int j;
	int nindex;
	int total_len;

	i = 0;
	nindex = 0;
	if (size == 0)
	{
		res = malloc(1);
		res[0] = '\0';
		return (res);
	}
	total_len = get_total_len(size, strs, sep);
	res = malloc(sizeof(total_len + 1));
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			res[nindex++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			res[nindex++] = sep[j++];
		i++;
	}
	res[nindex] = 0;
	return (res);
}

/*
#include <stdio.h>
int	main(void)
{
	// char	*tab[3];
	// tab[0] = "HELLO";
	// tab[1] = "WORLD";
	// tab[2] = "WELCO";
	char *tab[] = {"HELLO", "WORLD", "WELCO"};
	char sep[] = "-=-";
	printf("%s\n", ft_strjoin(3, tab, sep));
	return (0); 
}
*/