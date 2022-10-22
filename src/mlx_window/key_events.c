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
#include "mlx_and_struct.h"
#include "fractol.h"

static void	cli_ask(int key, t_fractol *fractol);
static void	move_center(int key, t_fractol *fractol);

void	key_compare(int key, t_fractol *fractol)
{
	ft_printf("\nKEY: %d\n", key);
	if (key == 53)
		end_fractol(fractol);
	else if (key == 126 || (key == 125)
		|| (key == 124) || (key == 123)
		|| (key == 8))
		move_center(key, fractol);
	else
		cli_ask(key, fractol);
}

static void	cli_ask(int key, t_fractol *fractol)
{
	if (key == 12)
	{
		fractol->plus_iter += 20;
		fractol->iter_max = fractol->plus_iter
			* pow(log10(fractol->setvalue.zoom + 10), 1.25);
	}
	else if (key == 13 && fractol->plus_iter > 20)
	{
		fractol->plus_iter -= 20;
		fractol->iter_max = fractol->plus_iter
			* pow(log10(fractol->setvalue.zoom + 10), 1.25);
	}
	else if (key == 257)
		fractol->shift_press = 1;
	else if (key == 17)
		theme_select(fractol);
}

static void	move_center(int key, t_fractol *fractol)
{
	if (key == 126)
		fractol->setvalue.ycenter -= fractol->center_modi;
	if (key == 125)
		fractol->setvalue.ycenter += fractol->center_modi;
	if (key == 124)
		fractol->setvalue.xcenter += fractol->center_modi;
	if (key == 123)
		fractol->setvalue.xcenter -= fractol->center_modi;
	if (key == 8)
	{
		fractol->setvalue.ycenter = 0;
		fractol->setvalue.xcenter = 0;
		fractol->setvalue.zoom = 0.5;
		fractol->center_modi = 0.1 / fractol->setvalue.zoom;
	}
}
