/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool_isdigit_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 00:49:06 by brattles          #+#    #+#             */
/*   Updated: 2021/08/31 22:49:02 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_bool_isdigit_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (ft_isdigit(str[i]) || ((str[0] == '-' || str[0] == '+') \
			&& ft_isdigit(str[1])))
			return (true);
	return (false);
}
