/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:20:38 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:21:05 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Support function for "double_atoi"
static void	atoi_utilities(const char *nptr, int dec, double *num, double *i)
{
	while (*nptr)
	{
		if (*nptr > 47 && *nptr < 58)
		{
			*num *= 10;
			*num = *num + (*nptr - 48);
		}
		if (*nptr == 46)
		{
			while (nptr[dec])
				dec++;
			while (dec--)
				*i *= 10;
		}
		nptr++;
	}
}

//	Function to convert a char to a double
double	double_atoi(const char *nptr, double num, double i)
{
	double	symb;

	symb = 1;
	if (*nptr == '-')
	{
		symb = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	atoi_utilities(nptr, 0, &num, &i);
	num /= i / 10;
	return (num * symb);
}
