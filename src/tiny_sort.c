/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:12:13 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 17:10:09 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_first_less(t_process_params *params)
{
	if ((*(params)->stack_a)->value > (*(params)->stack_a)->next->next->value)
		rra(params->stack_a);
	else
	{
		sa(params->stack_a);
		ra(params->stack_a);
	}
}

void	handle_first_greater(t_process_params *params)
{
	if ((*(params)->stack_a)->next->value > (*(params)->stack_a)->next
		->next->value)
	{
		sa(params->stack_a);
		rra(params->stack_a);
	}
	else if ((*(params)->stack_a)->value < (*(params)->stack_a)->next
		->next->value)
		sa(params->stack_a);
	else
		ra(params->stack_a);
}

void	sort_three(t_process_params *params)
{
	if (is_sorted_ascending(*(params)->stack_a))
		return ;
	if ((*(params)->stack_a)->value < (*(params)->stack_a)->next->value)
		handle_first_less(params);
	else
		handle_first_greater(params);
}

void	sort_up_to_five(t_process_params *params)
{
	t_stack	*tmp;
	int		min;
	int		median;

	min = 0;
	while (*(params->stack_a) && !is_sorted_ascending(*(params)->stack_a))
	{
		get_index_stack(params);
		median = stack_size(*(params->stack_a)) / 2;
		tmp = *(params->stack_a);
		while (tmp && tmp->index != min)
			tmp = tmp->next;
		while ((*(params->stack_a))->index != min)
		{
			if (tmp->order <= median)
				ra(params->stack_a);
			else
				rra(params->stack_a);
		}
		pb(params->stack_a, params->stack_b);
		if (stack_size(*(params->stack_a)) == 3)
			sort_three(params);
	}
	while (*params->stack_b != NULL)
		pa(params->stack_a, params->stack_b);
}

void	tiny_sort(t_process_params *params)
{
	int	size;

	size = stack_size(*(params->stack_a));
	if (params->stack_a && *(params->stack_a))
	{
		if (size == 2)
		{
			if ((*(params)->stack_a)->value > (*(params)->stack_a)->next->value)
				sa(params->stack_a);
		}
		else if (size == 3)
			sort_three(params);
		else if (size == 4 || size == 5)
			sort_up_to_five(params);
	}
}
