/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:42:48 by brattles          #+#    #+#             */
/*   Updated: 2021/08/31 00:22:40 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_panic(t_summary **summary)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (summary)
	{
		clear_lst(*summary);
		free(*summary);
		*summary = NULL;
	}
	exit(EXIT_FAILURE);
}
