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
#include "../inc/fractol.h"

//	Main function of the check input steep
int	check_input(int argc, char **argv, char *set)
{
	if (argc < 2 || argc > 4)
		return (error_msg(1));
	if (!ft_strncmp(argv[1], "Mandelbrot", 0xFFFFFF)
		|| !ft_strncmp(argv[1], "mandelbrot", 0xFFFFFF))
	{
		*set = 'm';
		if (argc > 2)
			return (error_msg(1));
	}
	else if (!ft_strncmp(argv[1], "Julia", 0xFFFFFF)
		|| !ft_strncmp(argv[1], "julia", 0xFFFFFF))
	{
		*set = 'j';
		if (argc > 4 || argc < 4)
			return (error_msg(1));
		if (!check_input_num(argv[2], 0, 0) || !check_input_num(argv[3], 0, 0))
			return (error_msg(2));
	}
	return (1);
}

//	Function to see if he written correctly the input values for the Julia set
int	check_input_num(char *num, int symb, int point)
{
	size_t	size;

	size = 0;
	while (*num)
	{
		if ((*num < 48 || *num > 57))
		{
			if ((*num == '+' || *num == '-') && symb)
				return (0);
			else if (*num == '.' && point)
				return (0);
			else if ((*num == '+' || *num == '-') && !symb)
				symb = 1;
			else if (*num == '.' && !point)
				point = 1;
			else
				return (0);
		}
		else
			size++;
		num++;
	}
	if (size < 1)
		return (0);
	return (1);
}

//	Has its name suggests, this function display the error and return 0
int	error_msg(int mode)
{
	if (mode == 1)
	{
		printf("Invalid number of arguments\n");
	}
	else if (mode == 2)
	{
		printf("Invalid input values for the fractal,");
		printf("make sure you are entering values correctly:\n");
	}
	printf("\nEnter the desired fractal as follows:\n");
	printf("- For Mandelbrod set type: mandelbrod\n");
	printf("- For Julia set type: julia (x value) (i value)\n");
	printf("\nExample: Julia -0.6 -0.4\n");
	return (0);
}
