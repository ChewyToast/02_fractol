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

char	*double_itoa(double num)
{
	char	*str;

	if (num < 0)
	{
		num *= -1;
		str = malloc(sizeof(char) * 4);
		if (!str)
			return (NULL);
		str[0] = '-';
		str[2] = ',';
		str[3] = '\0';
		str[1] = (num % 10) + 48;
		num -= (num % 10);
		num *= 10;
	}
	else
	{
		str = malloc(sizeof(char) * 3);
		if (!str)
			return (NULL);
		str[1] = ',';
		str[2] = '\0';
		*str = (num % 10) + 48;
		num -= (num % 10);
		num *= 10;
	}
	while (num % 10 != 0 && (num * 10) % 10 != 0)
	{
		*str = ft_strjoinn(str, &((num % 10) + 48));
		num -= (num % 10);
		num *= 10;
	}
	return (str);
}