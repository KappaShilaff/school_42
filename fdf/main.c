/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcassaun <lcassaun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:55:01 by lcassaun          #+#    #+#             */
/*   Updated: 2020/06/25 16:58:12 by lcassaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/libft/includes/libft.h"
#include <stdio.h>



//int 	main(void)
//{
//	void	*mlx_ptr;
//	void 	*win_ptr;
//	void 	*ptr;
//
//
//
//	mlx_ptr = mlx_init();
//	ptr = mlx_new_image(mlx_ptr, 100, 100);
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
//	mlx_put_image_to_window(mlx_ptr, win_ptr, ptr, 400, 400);
//	mlx_get_color_value(mlx_ptr, 0xffffff);
//	mlx_pixel_put(mlx_ptr, win_ptr, 300, 300, 0xffffff);
//	mlx_string_put(mlx_ptr, win_ptr, 200, 200, 0xffffff, "lol");
//	mlx_loop(mlx_ptr);
//}

int main(int ac, char **argv)
{
	char *line;
	int fd1;
	int fd2;
	fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(fd1, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}