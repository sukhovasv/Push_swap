/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:38:31 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 17:37:04 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int					index;
	int					value;
	int					order;
	struct s_stack		*next;
}	t_stack;

typedef struct s_stack_process
{
	int	processed;
	int	total;
	int	moved;
}	t_stack_process;

typedef struct s_process_params
{
	t_stack					**stack_a;
	t_stack					**stack_b;
	int						step;
	int						max_steps;
	t_stack_process			*process_a;
	t_stack_process			*process_b;
}	t_process_params;

bool		is_sorted_descending(t_stack *stack);
bool		is_sorted_ascending(t_stack *stack);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
int			get_median(t_stack *stack);
int			stack_size(t_stack *stack);
void		push(t_stack **stack, int value);
t_stack		*new_node(int value);
t_stack		*stack_init(int argc, char **argv);
void		bit_by_bit_processing(t_process_params *params);
void		sort_stack_b(t_stack **b, int step);
void		sort_stack_a(t_stack **a, int step);
void		initialize_process_params(t_process_params *params);
void		sort_both_stacks_bitwise(t_process_params *params);
void		process_stack_b(t_process_params *params);
void		process_stack_a(t_process_params *params);
void		divide_between_stacks(t_process_params *params);
void		free_resources(t_process_params *process_params);
int			initialize_all(t_process_params *process_params,
				int argc, char **argv);
void		rr(t_stack **a, t_stack **b);
void		rb(t_stack **b);
void		ra(t_stack **a);
void		rrr(t_stack **a, t_stack **b);
void		rrb(t_stack **b);
void		rra(t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		reset_processed_counters(t_process_params *params);
void		process_single_stack(t_process_params *params);
void		sort_stack_bitwise(t_process_params *params, int bit_a, int bit_b);
void		reset_processed_counters(t_process_params *params);
int			check_for_duplicates(char **arguments);
int			check_for_duplicates_one_arg(char **arguments);
int			check_for_limits(char **arguments);
int			check_for_limits_one_arg(char **arguments);
int			check_for_numeric(char **arguments);
int			check_for_numeric_one_arg(char **arguments);
void		get_index(t_process_params *params, int size);
void		get_index_stack(t_process_params *params);
void		get_index_order(t_process_params *params);
void		free_split(char **split);
void		free_stack(t_stack *stack);
void		free_stack_process(t_stack_process *process);
void		free_process_params(t_process_params *params);
int			max_steps(t_stack **stack);
void		print_stack(t_stack *stack);
void		tiny_sort(t_process_params *params);
void		release_all_resources(t_process_params *params);
void		process_and_move_elements_a(t_process_params *params);
void		return_elements_to_stack_a(t_process_params *params);
void		process_and_move_elements_b(t_process_params *params);
void		return_elements_to_stack_b(t_process_params *params);
void		sort_stacks_separately(t_process_params *params);
void		initialize_stacks(t_process_params *params);
void		initialize_stack_processes(t_process_params *params);
void		initialize_other_fields(t_process_params *params);
int			get_max_steps(t_stack **stack);
long long	ft_atoll(const char *nptr);

#endif
