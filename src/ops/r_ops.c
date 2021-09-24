/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:19:10 by brattles          #+#    #+#             */
/*   Updated: 2021/08/29 17:33:22 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_ops(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tmp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		tmp = (*stack)->next;
		while ((*stack)->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next = temp;
		temp->next = NULL;
		temp->previous = (*stack);
		tmp->previous = NULL;
		*stack = tmp;
	}
}
