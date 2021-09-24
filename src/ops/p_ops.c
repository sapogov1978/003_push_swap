/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:20:01 by brattles          #+#    #+#             */
/*   Updated: 2021/08/31 00:25:40 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	p_ops(t_stack **to, t_stack **from)
{
	t_stack	*tmp_from;
	t_stack	*temp_from;
	t_stack	*tmp_to;

	if (*from != NULL)
	{
		tmp_from = *from;
		temp_from = (*from)->next;
		tmp_to = *to;
		*from = temp_from;
		if (*to == NULL)
		{
			*to = tmp_from;
			(*to)->next = NULL;
			(*to)->previous = NULL;
		}
		else
		{
			*to = tmp_from;
			(*to)->next = tmp_to;
			(*to)->next->previous = tmp_from;
		}
		if (*from != NULL && (*from)->previous != NULL)
			(*from)->previous = NULL;
	}
}
