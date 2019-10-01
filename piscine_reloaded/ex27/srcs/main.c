/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:41:35 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/05 16:02:19 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_display(char *av)
{
	int		fd;
	int		mem;
	char	buf[4097];

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return ;
	while ((mem = read(fd, buf, 4096)))
	{
		buf[mem] = '\0';
		ft_putstr(buf);
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	ft_display(argv[1]);
	return (0);
}
