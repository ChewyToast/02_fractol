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

//static void	smart_zoom(t_fractol *fractol, int x, int y);

void	mouse_compare(int btn, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (btn == 5)
	{
		fractol->setvalue.zoom *= 1.25;
		fractol->iter_max = fractol->plus_iter
			* pow(log10(fractol->setvalue.zoom + 15), 1.15);
	}
	else if (btn == 4)
	{
		fractol->setvalue.zoom /= 1.25;
		fractol->iter_max = fractol->plus_iter
			* pow(log10(fractol->setvalue.zoom + 15), 1.15);
	}
	fractol->center_modi = 0.1 / fractol->setvalue.zoom;
}

// static void	smart_zoom(t_fractol *fractol, int x, int y, float zoom_value)
// {
// 	if (x > W / 2 && y > H / 2)
// 	{
// 		fractol->setvalue.xcenter += round(d->offset.x + ((W >> 1) - x) * );
// 		fractol->setvalue.ycenter += fractol->center_modi;
// 	}
// 	else if (x < W / 2 && y > H / 2)
// 	{
// 		fractol->setvalue.xcenter -= fractol->center_modi;
// 		fractol->setvalue.ycenter += fractol->center_modi;
// 	}
// 	else if (x > W / 2 && y < H / 2)
// 	{
// 		fractol->setvalue.xcenter += fractol->center_modi;
// 		fractol->setvalue.ycenter -= fractol->center_modi;
// 	}
// 	else if (x < W / 2 && y < H / 2)
// 	{
// 		fractol->setvalue.xcenter -= fractol->center_modi;
// 		fractol->setvalue.ycenter -= fractol->center_modi;
// 	}
// }
