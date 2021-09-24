/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:02:58 by brattles          #+#    #+#             */
/*   Updated: 2021/08/31 23:19:18 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_summary	*summary;

	summary = NULL;
	summary = ft_calloc(1, sizeof(t_summary));
	if (!summary)
		ft_panic(&summary);
	if (argc == 2 && !ft_atoi(argv[1]))
		ft_panic(&summary);
	if (argc > 2)
	{
		ft_parser(argv, summary);
		ft_solve_and_print(summary);
		clear_lst(summary);
	}
	free(summary);
	summary = NULL;
	return (EXIT_SUCCESS);
}
