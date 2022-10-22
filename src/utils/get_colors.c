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

// static void	hsv_rgb(int h, int s, int v, t_fractol *fractol);
static int	ft_round(double num);
static int	gradient(int startcolor, int endcolor, int len, int i);

int	get_color(int i, t_fractol *fractol)
{
	if (i == fractol->iter_max)
		return (0x1D1C1A);
	return (gradient(fractol->setcolor.start, fractol->setcolor.end,
			fractol->iter_max, i));
}

void	theme_select(t_fractol *fractol)
{
	fractol->setcolor.count++;
	if (fractol->setcolor.count == 1)
	{
		fractol->setcolor.start = 0x001833;
		fractol->setcolor.end = 0xFFE1AD;
	}
	else if (fractol->setcolor.count == 2)
	{
		fractol->setcolor.start = 0x003321;
		fractol->setcolor.end = 0xFFCBBF;
	}
	else if (fractol->setcolor.count == 3)
	{
		fractol->setcolor.start = 0x403801;
		fractol->setcolor.end = 0xD3BFFF;
	}
	else if (fractol->setcolor.count == 4)
	{
		fractol->setcolor.start = 0x331E0C;
		fractol->setcolor.end = 0xBFF4FF;
	}
	else
	{
		fractol->setcolor.start = 0x250040;
		fractol->setcolor.end = 0xF7FFBF;
		fractol->setcolor.count = 0;
	}
}

static int	gradient(int startcolor, int endcolor, int len, int i)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((endcolor >> 16) - \
					(startcolor >> 16)) / (double)len;
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - \
					((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) \
					/ (double)len;
	new[0] = (startcolor >> 16) + ft_round(i * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(i * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(i * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

static int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}
