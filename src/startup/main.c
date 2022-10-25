/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:58:23 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/10/25 17:58:30 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "mlx_and_struct.h"

static size_t	program_startup(char **argv);

//	Main function, thr we call the checker and if its correct start the program
int	main(int argc, char **argv)
{
	if (!check_input(argc, argv))
		exit (error_msg(0));
	if (!program_startup(argv))
		exit (error_msg(6));
	exit (0);
}

//	Program controller function
static size_t	program_startup(char **argv)
{
	t_fractol	fractol;

	init_fractol(&fractol, argv);
	if (!window_startup(&fractol))
		end_fractol(&fractol);
	fractol_hooks(&fractol);
	return (1);
}
