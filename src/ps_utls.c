/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 00:36:48 by brattles          #+#    #+#             */
/*   Updated: 2021/08/31 00:23:16 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	stack_max(t_stack *stack, int max)
{
	t_stack	*tmp;

	max = INT_MIN;
	tmp = stack;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->value > max)
				max = tmp->value;
			tmp = tmp->next;
		}
		if (tmp->value > max)
			max = tmp->value;
	}
	return (max);
}

int	stack_min(t_stack *stack, int min)
{
	t_stack	*tmp;

	min = INT_MAX;
	tmp = stack;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->value < min)
				min = tmp->value;
			tmp = tmp->next;
		}
		if (tmp->value < min)
			min = tmp->value;
	}
	return (min);
}

void	clear_lst(t_summary *summary)
{
	t_stack	*temp;
	t_stack	*tmp;

	temp = summary->a;
	if (temp != NULL)
	{
		while (temp && temp->next != NULL)
			temp = temp->next;
		while (temp && temp->previous != NULL)
		{
			tmp = temp->previous;
			free(temp);
			temp = tmp;
		}
		free(temp);
	}
}
