/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 01:12:33 by brattles          #+#    #+#             */
/*   Updated: 2021/08/27 12:22:17 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_stack_sorted(t_summary *summary)
{
	t_stack	*tmp;

	tmp = summary->a;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	ft_is_arr_sorted(int *temp_arr, t_summary *summary)
{
	int		i;

	i = 1;
	while (i <= summary->a_el_count - 1)
	{
		if (temp_arr[i] < temp_arr[i - 1])
			return (false);
		i++;
	}
	return (true);
}
