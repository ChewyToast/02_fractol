/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:23:12 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:24:12 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_AND_STRUC_H
# define MLX_AND_STRUC_H

//	LIBRARY FOR THE MLX FUNCTIONS
# include "../mlx/mlx.h"

// 						~ STRUCTS ~

typedef struct s_fractol	t_fractol;

//	Function definition to be associated to a fractal
typedef void	(*t_fdrawer)(t_fractol *fractol);

//	Containing structure of screen pointers
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

//	Main struct
struct s_fractol
{
	t_mlx		screen;
	t_fdrawer	t_fdrawer;
	double		zoom;
	double		xcenter;
	double		ycenter;
	double		cx;
	double		cy;
};

// 						~ MACROS ~

# define W 1200
# define H 800
# define ITER_MAX 100

#endif