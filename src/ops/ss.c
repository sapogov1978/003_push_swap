/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 00:58:00 by brattles          #+#    #+#             */
/*   Updated: 2021/07/23 13:15:45 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_summary *summary)
{
	sa(summary, 0);
	sb(summary, 0);
	ft_putendl_fd("ss", STDOUT_FILENO);
}
