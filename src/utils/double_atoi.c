/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:59:25 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/10/25 17:59:33 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Support function for "double_atoi"
static void	atoi_utilities(char *nptr, int dec, double *num, double *i)
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
double	double_atoi(char *nptr, double num, double i)
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
