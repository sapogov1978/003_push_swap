/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:07:39 by brattles          #+#    #+#             */
/*   Updated: 2021/08/30 01:41:43 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_ops(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tmp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = *stack;
		while (*stack && (*stack)->next && (*stack)->next->next)
			*stack = (*stack)->next;
		temp = (*stack)->next;
		(*stack)->next = NULL;
		temp->next = tmp;
		*stack = temp;
		(*stack)->previous = NULL;
		(*stack)->next->previous = temp;
	}
}
