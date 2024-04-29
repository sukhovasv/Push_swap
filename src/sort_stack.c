/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:13:24 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 16:14:40 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_stack_a(t_process_params *params)
{
	int	total;
	int	processed;
	int	moved_count;
	int	current_bit;

	total = params->process_a->total;
	processed = params->process_a->processed;
	moved_count = params->process_a->moved;
	while (processed++ < total)
	{
		current_bit = ((*params->stack_a)->index >> params->step) & 1;
		if (current_bit == 0)
		{
			pb(params->stack_a, params->stack_b);
			moved_count++;
		}
		else
			ra(params->stack_a);
	}
	while (moved_count-- > 0)
		pa(params->stack_a, params->stack_b);
	params->process_a->processed = 0;
	params->process_a->moved = 0;
}

void	process_stack_b(t_process_params *params)
{
	int	total;
	int	processed;
	int	moved_count;
	int	current_bit;

	total = params->process_b->total;
	processed = params->process_b->processed;
	moved_count = params->process_b->moved;
	while (processed++ < total)
	{
		current_bit = ((*params->stack_b)->index >> params->step) & 1;
		if (current_bit == 1)
		{
			pa(params->stack_a, params->stack_b);
			moved_count++;
		}
		else
			rb(params->stack_b);
	}
	while (moved_count-- > 0)
		pb(params->stack_a, params->stack_b);
	params->process_b->processed = 0;
	params->process_b->moved = 0;
}

void	sort_stacks_separately(t_process_params *params)
{
	if (!is_sorted_ascending(*params->stack_a)
		&& !is_sorted_descending(*params->stack_b))
	{
		process_stack_a(params);
		process_stack_b(params);
	}
	else if (is_sorted_ascending(*params->stack_a)
		&& !is_sorted_descending(*params->stack_b))
		process_stack_b(params);
	else if (!is_sorted_ascending(*params->stack_a)
		&& is_sorted_descending(*params->stack_b))
		process_stack_a(params);
	params->step++;
}
