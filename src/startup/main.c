/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:16:23 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:16:57 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/headers/fractol.h"
#include "../../inc/headers/mlx_and_struct.h"

static int	program_startup(char select, char **argv);

//	Main function, thr we call the checker and if its correct start the program
int	main(int argc, char **argv)
{
	char	set;

	if (!check_input(argc, argv, &set))
		return (0);
	if (set == 'm')
		printf("Mandelbrot set selected\n");
	if (set == 'j')
		printf("Julia set selected\n");
	if (!program_startup(set, argv))
		return (0);
}

//	Program controller function
static int	program_startup(char select, char **argv)
{
	t_fractol	fractol;

	init_fract(&fractol, select, argv);
	if (!window_startup(&fractol))
	{
		mlx_destroy_window(fractol.screen.ptr, fractol.screen.win);
		return (0);
	}
	fractol.t_fdrawer(&fractol);
	mlx_loop(fractol.screen.ptr);
	return (1);
}
