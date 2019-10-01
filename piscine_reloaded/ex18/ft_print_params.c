/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:23:15 by lcassaun          #+#    #+#             */
/*   Updated: 2019/09/03 19:29:33 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(char *av)
{
	int		i;

	i = 0;
	while (av[i])
		ft_putchar(av[i++]);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
		ft_print_params(argv[i++]);
	return (0);
}
