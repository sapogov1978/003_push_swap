/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_indexing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 00:18:05 by brattles          #+#    #+#             */
/*   Updated: 2021/08/29 12:19:45 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_arr_from_lst(int *temp_arr, t_summary *summary)
{
	t_stack	*temp;
	int		i;

	temp = summary->a;
	i = 1;
	while (temp->next != NULL)
	{
		if (temp->value == summary->a_min)
			temp_arr[0] = temp->value;
		else if (temp->value == summary->a_max)
			temp_arr[summary->a_el_count - 1] = temp->value;
		else
			temp_arr[i++] = temp->value;
		temp = temp->next;
	}
	if (temp->value == summary->a_min)
		temp_arr[0] = temp->value;
	else if (temp->value == summary->a_max)
		temp_arr[summary->a_el_count - 1] = temp->value;
	else
		temp_arr[i] = temp->value;
}

static void	lst_indexing(t_summary *summary, int *temp_arr)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (i < summary->a_el_count)
	{
		temp = summary->a;
		while (temp->next != NULL)
		{
			if (temp->value == temp_arr[i])
				temp->index = i;
			temp = temp->next;
		}
		if (temp->value == temp_arr[i])
			temp->index = i;
		i++;
	}
}

static void	buble_sort(int *temp_arr, t_summary *summary)
{
	int	i;
	int	tmp;

	while (!ft_is_arr_sorted(temp_arr, summary))
	{
		i = 1;
		while (i < summary->a_el_count - 1)
		{
			if (temp_arr[i] < temp_arr[i - 1])
			{
				tmp = temp_arr[i - 1];
				temp_arr[i - 1] = temp_arr[i];
				temp_arr[i] = tmp;
			}
			i++;
		}
	}
}

void	run_once(t_summary *summary)
{
	int		*temp_arr;

	temp_arr = (int *)malloc(sizeof(int) * (summary->a_el_count));
	if (!temp_arr)
		ft_panic(&summary);
	fill_arr_from_lst(temp_arr, summary);
	buble_sort(temp_arr, summary);
	lst_indexing(summary, temp_arr);
	free(temp_arr);
	temp_arr = NULL;
}
