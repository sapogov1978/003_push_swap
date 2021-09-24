/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:17:46 by brattles          #+#    #+#             */
/*   Updated: 2021/08/27 13:45:58 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	int_value;
	int		isnegative;

	int_value = 0;
	isnegative = 1;
	while (ft_isspace(*nptr) != 0 || *nptr == '0' \
		|| *nptr == '+' || *nptr == '-')
	{
		if ((*nptr == '+' || *nptr == '-') && ft_isdigit(*(nptr + 1)) == 0)
			return (0);
		if (*nptr == '-')
			isnegative = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) != 0)
	{
		int_value = ((int_value * 10) + (*nptr - '0'));
		nptr++;
	}
	if (isnegative == -1)
		int_value = int_value * -1;
	if (int_value > INT_MAX || int_value < INT_MIN)
		return (0);
	return ((int)int_value);
}
