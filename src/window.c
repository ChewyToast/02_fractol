/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:20:02 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:20:29 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/fractol.h"

//	Init popup screen
int	window_startup(t_fractol *fractol)
{
	fractol->screen.ptr = mlx_init();
	if (!fractol->screen.ptr)
		return (0);
	fractol->screen.win = mlx_new_window(fractol->screen.ptr, W, H, "fractol");
	if (!fractol->screen.win)
		return (0);
	return (1);
}
