/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:14:12 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 16:03:36 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_between_stacks(t_process_params *params)
{
	int	size_a;
	int	median;
	int	processed;

	size_a = stack_size(*(params->stack_a));
	median = get_median(*(params->stack_a));
	processed = 0;
	while (processed < size_a)
	{
		if ((*(params->stack_a))->index < median)
			pb(params->stack_a, params->stack_b);
		else
			ra(params->stack_a);
		processed++;
	}
}

void	bit_by_bit_processing(t_process_params *params)
{
	params->max_steps = get_max_steps(params->stack_a);
	params->process_a->total = stack_size(*(params->stack_a));
	params->process_b->total = stack_size(*(params->stack_b));
	while ((params->step < params->max_steps)
		|| (!is_sorted_ascending(*params->stack_a)
			&& !is_sorted_descending(*params->stack_b)))
	{
		sort_both_stacks_bitwise(params);
		params->process_a->processed = 0;
		params->process_b->processed = 0;
		params->step++;
	}
	while (*params->stack_b != NULL)
		pa(params->stack_a, params->stack_b);
}

void	sort_both_stacks_bitwise(t_process_params *params)
{
	int	bit_a;
	int	bit_b;

	while (params->step < params->max_steps
		|| !is_sorted_ascending(*params->stack_a)
		|| !is_sorted_descending(*params->stack_b))
	{
		bit_a = ((*params->stack_a)->index >> params->step) & 1;
		bit_b = ((*params->stack_b)->index >> params->step) & 1;
		sort_stack_bitwise(params, bit_a, bit_b);
		sort_stacks_separately(params);
	}
}

void	sort_stack_bitwise(t_process_params *params, int bit_a, int bit_b)
{
	while (((bit_a == 1 && bit_b == 0) || (bit_a == 1 && bit_b == 1)
			|| (bit_a == 0 && bit_b == 0))
		&& ((!is_sorted_ascending(*params->stack_a))
			&& (!is_sorted_descending(*params->stack_b))))
	{
		if (bit_a == 1 && bit_b == 0)
		{
			rr(params->stack_a, params->stack_b);
			(params->process_a->processed)++;
			(params->process_b->processed)++;
		}
		else if (bit_a == 1 && bit_b == 1)
		{
			ra(params->stack_a);
			(params->process_a->processed)++;
		}
		else if (bit_a == 0 && bit_b == 0)
		{
			rb(params->stack_b);
			(params->process_b->processed)++;
		}
		bit_a = ((*params->stack_a)->index >> params->step) & 1;
		bit_b = ((*params->stack_b)->index >> params->step) & 1;
	}
}
