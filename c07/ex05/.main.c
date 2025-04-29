#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str, char *charset);

int	main()
{
	char	**res;
	int		i = 0;

	res = ft_split("Hello Welcome To My World", " ");
	while (res[i])
	{
		printf ("word %d: %s\n", i, res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}