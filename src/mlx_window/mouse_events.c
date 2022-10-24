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

static void	smart_zoom(t_fractol *fractol, int x, int y, double zoom);

void	mouse_compare(int btn, int x, int y, t_fractol *fractol)
{
	if (btn == 5)
	{
		smart_zoom(fractol, x, y, 1.25);
		fractol->setvalue.zoom *= 1.25;
		fractol->iter_max = fractol->plus_iter
			* pow(log10(fractol->setvalue.zoom + 15), 1.15);
	}
	else if (btn == 4)
	{
		smart_zoom(fractol, x, y, 0.8);
		fractol->setvalue.zoom *= 0.8;
		fractol->iter_max = fractol->plus_iter
			* pow(log10(fractol->setvalue.zoom + 15), 1.15);
	}
	fractol->center_modi = 0.1 / fractol->setvalue.zoom;
}

static void	smart_zoom(t_fractol *fractol, int x, int y, double zoom)
{
	double	xcalc;
	double	ycalc;
	double	new_xcalc;
	double	new_ycalc;

	xcalc = (x - (W >> 1)) / ((W >> 2) * fractol->setvalue.zoom);
	ycalc = (y - (H >> 1)) / ((H >> 2) * fractol->setvalue.zoom);
	new_xcalc = ((x - (W >> 1)) / ((W >> 2) * fractol->setvalue.zoom * zoom));
	new_ycalc = ((y - (H >> 1)) / ((H >> 2) * fractol->setvalue.zoom * zoom));
	fractol->setvalue.xcenter += xcalc - new_xcalc;
	fractol->setvalue.ycenter += ycalc - new_ycalc;
}
