/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:57:40 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/10/25 17:57:46 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "mlx_and_struct.h"

int	mlx_keyrelase(int key, t_fractol *fractol)
{
	if (key == 257)
		fractol->shift_press = 0;
	drawer(fractol);
	return (1);
}

int	mlx_keypress(int key, t_fractol *fractol)
{
	key_compare(key, fractol);
	drawer(fractol);
	return (1);
}

int	mlx_mousepress(int btn, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	mouse_compare(btn, x, y, fractol);
	drawer(fractol);
	return (1);
}
