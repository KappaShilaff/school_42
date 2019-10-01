/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:13:12 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/04 12:35:38 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int ac, char **av)
{
	int		i;
	int		j;
	char	*temp[0];

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				temp[0] = av[i];
				av[i] = av[j];
				av[j] = temp[0];
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	ft_sort_params(argc, argv);
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}
