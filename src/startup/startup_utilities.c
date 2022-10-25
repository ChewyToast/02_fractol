/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:18:20 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:18:42 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "mlx_and_struct.h"

static int	check_value(char *value);
static int	extra_check_value(char *value);

//	Main function of the check input steep
size_t	check_input(int argc, char **argv)
{
	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 0xFFFFFF)
			|| !ft_strncmp(argv[1], "julia", 0xFFFFFF)
			|| !ft_strncmp(argv[1], "tricorn", 0xFFFFFF)
			|| !ft_strncmp(argv[1], "burningship", 0xFFFFFF)))
		return (1);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 0xFFFFFF))
	{
		if (!check_value(argv[2]) || !check_value(argv[3]))
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	check_value(char *value)
{
	char	*point;

	if (*value == '+' || *value == '-')
		value++;
	point = ft_strchr(value, '.');
	if (point && point - value <= 1 && ft_strlen(value) - ft_strlen(point) <= 2)
		return (extra_check_value(value));
	else if (!point && ft_strlen(value) <= 1)
		return (extra_check_value(value));
	return (0);
}

static int	extra_check_value(char *value)
{
	char	point;

	point = 0;
	while (*value)
	{
		if (*value == '+' || *value == '-')
			return (0);
		if (*value >= '0' && *value <= '9')
			value++;
		else if (*value == '.' && point == 0)
		{
			value++;
			point++;
		}
		else
			return (0);
	}
	return (1);
}

//	Has its name suggests, this function display the error and return 0
size_t	error_msg(int mode)
{
	if (mode == 6)
	{
		write(2, "\033[0;91mUnexpected error\033[0;39m\n", 31);
//		ft_printf("\033[0;91mUnexpected error\033[0;39m");
		return (0);
	}
	else
	{
		write(2, "\033[0;91mInvalid input\033[0;39m", 27);
		ft_printf(" make sure you are entering values correctly:\n");
	}
	ft_printf("\nEnter the desired fractal as follows:");
	ft_printf("\n⚜️  For \033[4mMandelbrot\033[0m set type: mandelbrot.");
	ft_printf("\n⚜️  For \033[4mJulia\033[0m set type: julia;");
	ft_printf(" or julia \033[3m(x value) (i value)\033[0m.");
	ft_printf("\n⚜️  For \033[4mTricorn\033[0m set type: tricorn");
	ft_printf("\n⚜️  For \033[4mBurning\033[0m Ship set type: burningship");
	ft_printf("\n\nRemember that the Julia set is only drawn ");
	ft_printf("between small values so only ");
	ft_printf("\ninputs between 9 and -9 and with up to ");
	ft_printf("2 decimal places will be accepted\n");
	return (0);
}
