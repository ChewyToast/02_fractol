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
#include "fractol.h"
#include "mlx_and_struct.h"

static size_t	program_startup(char select, char **argv);

//	Main function, thr we call the checker and if its correct start the program
int	main(int argc, char **argv)
{
	char	set;

	if (!check_input(argc, argv, &set))
		exit (0);
	if (!program_startup(set, argv))
		exit (error_msg(6));
	exit (0);
}

//	Program controller function
static size_t	program_startup(char select, char **argv)
{
	t_fractol	fractol;

	init_fractol(&fractol, select, argv);
	if (!window_startup(&fractol))
		end_fractol(&fractol);
	fractol_hooks(&fractol);
	return (1);
}
