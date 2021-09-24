/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 00:58:00 by brattles          #+#    #+#             */
/*   Updated: 2021/08/30 00:53:24 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_summary *summary, bool print_flag)
{
	p_ops(&summary->a, &summary->b);
	(summary->a_el_count)++;
	(summary->b_el_count)--;
	summary->a_max = stack_max(summary->a, summary->a_max);
	summary->a_min = stack_min(summary->a, summary->a_min);
	summary->b_max = stack_max(summary->b, summary->b_max);
	summary->a_min = stack_min(summary->b, summary->b_min);
	if (print_flag)
		ft_putendl_fd("pa", STDOUT_FILENO);
}
