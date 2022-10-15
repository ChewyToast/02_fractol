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


void	mouse_compare(int btn, t_fractol *fractol)
{
	if (btn == 5)
	{
		fractol->setvalue.zoom *= 1.25;
		fractol->iter_max = fractol->plus_iter * pow(log10(fractol->setvalue.zoom + 10), 1.25);
	}
	else if (btn == 4)
	{
		fractol->setvalue.zoom /= 1.25;
		fractol->iter_max = fractol->plus_iter * pow(log10(fractol->setvalue.zoom + 10), 1.25);
	}
	fractol->center_modi = 0.1 / fractol->setvalue.zoom;
//	printf("Iter_value: %d\n", fractol->iter_max);
//	printf("Zoom value: %f\n", fractol->setvalue.zoom);
}
