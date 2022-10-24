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

static void	mjulia(t_fractol *fractol);
static void	mmandelbrot(t_fractol *fractol);
static void	mburningship(t_fractol *fractol);
static void	mtricorn(t_fractol *fractol);

//	Function to print the menu
void	mdrawer(t_fractol *fractol)
{
	char	*tmp;

	tmp = ft_itoa(fractol->iter_max);
	if (fractol->set == 'm')
		mmandelbrot(fractol);
	else if (fractol->set == 'j')
		mjulia(fractol);
	else if (fractol->set == 'b')
		mburningship(fractol);
	else if (fractol->set == 't')
		mtricorn(fractol);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1100, 630, PCL, GSA);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1100, 645, PCL, GSB);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1100, 700, PCL, GSC);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1100, 715, PCL, GSD);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1225, 715, PCL, tmp);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1100, 770, PCL, GSE);
	free (tmp);
}

static void	mmandelbrot(t_fractol *fractol)
{
	mlx_str_put2(fractol->screen.ptr, fractol->screen.win, 1127, 30, PCL, MSA);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1125, 52, PCL, MSB);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1131, 100, PCL, MSC);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1127, 120, PCL, MSD);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1140, 140, PCL, MSE);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1136, 160, PCL, MSF);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1135, 180, PCL, MSG);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1138, 200, PCL, MSH);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1130, 220, PCL, MSI);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1142, 240, PCL, MSJ);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1130, 260, PCL, MSK);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1126, 280, PCL, MSL);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1149, 300, PCL, MSM);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1140, 320, PCL, MSN);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1124, 340, PCL, MSO);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1148, 360, PCL, MSP);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1154, 385, PCL, MSQ);
}

static void	mjulia(t_fractol *fractol)
{
	mlx_str_put2(fractol->screen.ptr, fractol->screen.win, 1155, 30, PCL, JSA);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1154, 52, PCL, JSB);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1135, 100, PCL, JSC);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1115, 120, PCL, JSD);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1150, 140, PCL, JSE);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1115, 160, PCL, JSF);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1117, 180, PCL, JSG);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1114, 200, PCL, JSH);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1130, 220, PCL, JSI);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1129, 240, PCL, JSJ);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1118, 260, PCL, JSK);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1160, 285, PCL, JSL);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1100, 560, PCL, JSM);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1100, 575, PCL, JSN);
}

static void	mtricorn(t_fractol *fractol)
{
	mlx_str_put2(fractol->screen.ptr, fractol->screen.win, 1165, 30, PCL, TSA);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1165, 52, PCL, TSB);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1129, 100, PCL, TSC);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1106, 120, PCL, TSD);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1135, 140, PCL, TSE);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1125, 160, PCL, TSF);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1140, 180, PCL, TSG);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1120, 200, PCL, TSH);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1120, 220, PCL, TSI);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1154, 245, PCL, TSJ);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1124, 270, PCL, TSK);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1116, 290, PCL, TSL);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1136, 310, PCL, TSM);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1122, 330, PCL, TSN);
}

static void	mburningship(t_fractol *fractol)
{
	mlx_str_put2(fractol->screen.ptr, fractol->screen.win, 1135, 30, PCL, BSA);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1134, 52, PCL, BSB);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1124, 100, PCL, BSC);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1126, 120, PCL, BSD);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1158, 140, PCL, BSE);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1126, 160, PCL, BSF);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1120, 180, PCL, BSG);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1115, 200, PCL, BSH);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1118, 225, PCL, BSI);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1118, 250, PCL, BSJ);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1124, 270, PCL, BSK);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1153, 290, PCL, BSL);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1120, 310, PCL, BSM);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1120, 330, PCL, BSN);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1123, 350, PCL, BSO);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1107, 370, PCL, BSP);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1118, 390, PCL, BSQ);
	mlx_str_put(fractol->screen.ptr, fractol->screen.win, 1136, 410, PCL, BSR);
}
