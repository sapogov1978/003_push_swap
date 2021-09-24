/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brattles <brattles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 22:04:27 by brattles          #+#    #+#             */
/*   Updated: 2021/09/01 00:08:59 by brattles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# undef  INT_MIN
# undef  INT_MAX
# define INT_MAX   2147483647
# define INT_MIN   -2147483648

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdbool.h>

typedef struct s_summary	t_summary;
typedef struct s_stack		t_stack;

struct s_stack {
	int					value;
	unsigned int		index;
	struct s_stack		*previous;
	struct s_stack		*next;
};

struct s_summary {
	int					a_el_count;
	int					b_el_count;
	int					a_max;
	int					b_max;
	int					a_min;
	int					b_min;
	struct s_stack		*a;
	struct s_stack		*b;
};

/* General Functions */
int		main(int argc, char **argv);
void	ft_panic(t_summary **summary);
void	ft_parser(char **argv, t_summary *summary);
void	ft_solve_and_print(t_summary *summary);
void	ft_small_sort(t_summary *summary);
void	ft_medium_sort(t_summary *summary);
void	ft_big_sort(t_summary *summary);

/* Utility functions */
bool	ft_bool_isdigit_str(char *c);
bool	ft_is_stack_sorted(t_summary *summary);
bool	ft_is_arr_sorted(int *temp_arr, t_summary *summary);
int		stack_max(t_stack *stack, int max);
int		stack_min(t_stack *stack, int min);
void	run_once(t_summary *summary);
void	clear_lst(t_summary *summary);

/* Ops Functions */
void	pa(t_summary *summary, bool print_flag);
void	pb(t_summary *summary, bool print_flag);
void	p_ops(t_stack **to, t_stack **from);
void	sa(t_summary *summary, bool print_flag);
void	sb(t_summary *summary, bool print_flag);
void	ss(t_summary *summary);
void	s_ops(t_stack **stack);
void	ra(t_summary *summary, bool print_flag);
void	rb(t_summary *summary, bool print_flag);
void	rr(t_summary *summary);
void	r_ops(t_stack **stack);
void	rra(t_summary *summary, bool print_flag);
void	rrb(t_summary *summary, bool print_flag);
void	rrr(t_summary *summary);
void	rr_ops(t_stack **stack);

#endif
