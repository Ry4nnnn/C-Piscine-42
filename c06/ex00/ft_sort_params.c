
void	sort(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
				ft_swap(&av[i], &av[j]);
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int i;
	
	i = 1;
	if (ac == 1)
		return (0);
	sort (ac, av);
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}