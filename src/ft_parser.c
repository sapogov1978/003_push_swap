/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 02:00:11 by brattles          #+#    #+#             */
/*   Updated: 2021/08/31 23:47:22 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static void	ft_lst_add(t_summary *summary, int arg)
{
	t_stack	*temp;

	temp = summary->a;
	while (temp->next != NULL)
	{
		if (arg == temp->value)
			ft_panic(&summary);
		temp = temp->next;
	}
	if (arg == temp->value)
		ft_panic(&summary);
	temp->next = ft_calloc(1, sizeof(t_stack));
	if (!temp->next)
		ft_panic(&summary);
	temp->next->previous = temp;
	temp->next->value = arg;
	summary->a->index = 0;
	(summary->a_el_count)++;
}

static void	ft_lst_new(t_summary *summary, int arg)
{
	summary->a = ft_calloc(1, sizeof(t_stack));
	if (!summary->a)
		ft_panic(&summary);
	summary->a->value = arg;
	summary->a->index = 0;
	(summary->a_el_count)++;
}

static void	ft_init(t_summary *summary)
{
	summary->a_max = INT_MIN;
	summary->b_max = INT_MIN;
	summary->a_min = INT_MAX;
	summary->b_min = INT_MAX;
	summary->a_el_count = 0;
	summary->b_el_count = 0;
}

void	ft_parser(char **argv, t_summary *summary)
{
	int		arg;
	int		i;

	i = 1;
	ft_init(summary);
	while (argv[i])
	{
		arg = ft_atoi(argv[i]);
		if (arg > INT_MAX || arg < INT_MIN)
			ft_panic(&summary);
		if (arg == 0 && (!ft_bool_isdigit_str(argv[i]) || \
			ft_strlen(argv[i]) > 1))
			ft_panic(&summary);
		if (!summary->a)
			ft_lst_new(summary, arg);
		else
			ft_lst_add(summary, arg);
		i++;
	}
	summary->a_max = stack_max(summary->a, summary->a_max);
	summary->a_min = stack_min(summary->a, summary->a_min);
}
