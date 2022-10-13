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

int	mlx_keypress(int key, t_fractol *fractol)
{
	key_compare(key, fractol);
	fractol->t_fdrawer(fractol);
	return (1);
}

int	mlx_mousepress(int btn, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	ft_printf("\nbtnpressed: <%d>", btn);
	if (btn == 5)
		fractol->setvalue.zoom *= 2;
	else if (btn == 4)
	{
		if (fractol->setvalue.zoom > 1)
			fractol->setvalue.zoom /= 2;
	}
	fractol->t_fdrawer(fractol);
	printf("zoom value: %lld", fractol->setvalue.zoom);
	ft_printf("\nMOUSE PRINT DONE");
	return (1);
}
