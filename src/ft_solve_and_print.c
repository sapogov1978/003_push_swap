/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_and_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 01:12:33 by brattles          #+#    #+#             */
/*   Updated: 2021/08/27 13:47:57 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort(t_summary *summary)
{
	if (summary->a_el_count == 1)
		return ;
	if (summary->a_el_count == 2 && summary->a->value > summary->a_min)
		ra(summary, 1);
	if (summary->a_el_count == 3)
	{
		if (summary->a->value == summary->a_max)
			ra(summary, 1);
		else if (summary->a->next->value == summary->a_max)
			rra(summary, 1);
		else if (summary->a->value > summary->a->next->value)
			sa(summary, 1);
	}
}

void	ft_medium_sort(t_summary *summary)
{
	while (summary->a_el_count > 3)
	{
		if (summary->a->value == summary->a_min)
			pb(summary, 1);
		else
			ra(summary, 1);
	}
	while (ft_is_stack_sorted(summary) == false)
		ft_small_sort(summary);
	while (summary->b_el_count > 0)
		pa(summary, 1);
}

void	ft_big_sort(t_summary *summary)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	run_once(summary);
	while (!ft_is_stack_sorted(summary))
	{
		j = 0;
		len = summary->a_el_count;
		while (j++ < len)
		{
			if ((summary->a->index >> i) & 1)
				ra(summary, 1);
			else
				pb(summary, 1);
		}
		while (summary->b_el_count > 0)
			pa(summary, 1);
		i++;
	}
}

void	ft_solve_and_print(t_summary *summary)
{
	while (ft_is_stack_sorted(summary) == false)
	{
		if (summary->a_el_count <= 3)
			ft_small_sort(summary);
		else if (summary->a_el_count > 3 && summary->a_el_count <= 5)
			ft_medium_sort(summary);
		else
			ft_big_sort(summary);
	}
}
