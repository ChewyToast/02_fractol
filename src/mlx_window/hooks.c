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
#include "fractol.h"
#include "mlx_and_struct.h"

int	mouse_loop(t_fractol *fractol)
{
	int		x;
	int		y;

	if (fractol->set == 'j' && fractol->shift_press == 1)
	{
		mlx_mouse_get_pos(fractol->screen.win, &x, &y);
		fractol->setvalue.cx = (double)(x
				* (4 / fractol->setvalue.zoom)
				/ W - (2 / fractol->setvalue.zoom));
		fractol->setvalue.cy = (double)(y
				* (3 / fractol->setvalue.zoom)
				/ H - (1.5 / fractol->setvalue.zoom));
		drawer(fractol);
	}
	return (0);
}

void	fractol_hooks(t_fractol *fractol)
{
	drawer(fractol);
	mlx_hook(fractol->screen.win, 2, 0, mlx_keypress, fractol);
	mlx_hook(fractol->screen.win, 3, 0, mlx_keyrelase, fractol);
	mlx_hook(fractol->screen.win, 4, 0, mlx_mousepress, fractol);
	mlx_hook(fractol->screen.win, 17, 0, end_fractol, fractol);
	mlx_loop_hook(fractol->screen.ptr, mouse_loop, fractol);
	mlx_loop(fractol->screen.ptr);
}
