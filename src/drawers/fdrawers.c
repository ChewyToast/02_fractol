/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdrawers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:52:39 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/17 22:53:07 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_and_struct.h"
#include "fractol.h"

static	void	func_prepare(t_fractol *fractol, int x, int y);
static int	function_iterate(t_fractol *fractol);

void	screen_iterate(t_fractol *fractol)
{
	int		x;
	int		y;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			func_prepare(fractol, x, y);
			my_pixel_put(fractol, x++, y,
				get_color(function_iterate(fractol), fractol));
		}
		y++;
	}
}

static	void	func_prepare(t_fractol *fractol, int x, int y)
{
	if (fractol->set == 'm' || fractol->set == 'b' || fractol->set == 't')
	{
		fractol->setvalue.cx = (1.5 * (x - (W >> 1))
				/ (fractol->setvalue.zoom * (W >> 1))
				+ (fractol->setvalue.xcenter));
		fractol->setvalue.cy = ((y - (H >> 1))
				/ (fractol->setvalue.zoom * (H >> 1))
				+ (fractol->setvalue.ycenter));
		fractol->setvalue.xiter = 0;
		fractol->setvalue.yiter = 0;
	}
	else if (fractol->set == 'j')
	{
		fractol->setvalue.xiter = (1.5 * (x - (W >> 1))
						/ (fractol->setvalue.zoom * (W >> 1))
						+ (fractol->setvalue.xcenter));
		fractol->setvalue.yiter = ((y - (H >> 1))
						/ (fractol->setvalue.zoom * (H >> 1))
						+ (fractol->setvalue.ycenter));
	}
}

static int	function_iterate(t_fractol *fractol)
{
	int		i;
	double	old_x_iter;
	double	old_y_iter;

	i = 0;
	while (i < fractol->iter_max
		&& ((XIT * XIT + YIT * YIT) < 4))
	{
		if (fractol->set == 'b')
		{
			old_x_iter = fabs(XIT);
			old_y_iter = fabs(YIT);
		}
		else
		{
			old_x_iter = XIT;
			old_y_iter = YIT;
		}
		XIT = (((old_x_iter * old_x_iter)
					- (old_y_iter * old_y_iter)) + (fractol->setvalue.cx));
		YIT = VAL * old_x_iter * old_y_iter + (fractol->setvalue.cy);
		i++;
	}
	return (i);
}