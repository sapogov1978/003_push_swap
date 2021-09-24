/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:49:41 by brattles          #+#    #+#             */
/*   Updated: 2021/08/29 18:10:08 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_ops(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		tmp = (*stack)->next;
		*stack = tmp->next;
		tmp->next = temp;
		tmp->previous = NULL;
		temp->next = *stack;
		temp->previous = tmp;
		(*stack)->previous = temp;
		*stack = tmp;
	}
}
