/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:16:46 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 15:18:24 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_process_params *params, int size)
{
	t_stack	*tmp;
	t_stack	*min_ptr;
	int		index;

	index = 0;
	if (params->stack_a && *(params->stack_a))
	{
		while (size--)
		{
			min_ptr = NULL;
			tmp = *(params->stack_a);
			while (tmp)
			{
				if (tmp->index == -1 && (!min_ptr || tmp->value
						< min_ptr->value))
					min_ptr = tmp;
				tmp = tmp->next;
			}
			if (min_ptr)
				min_ptr->index = index++;
		}
	}
}

void	get_index_order(t_process_params *params)
{
	t_stack	*tmp;
	int		i;

	tmp = *(params->stack_a);
	if (params->stack_a && *(params->stack_a))
	{
		i = 0;
		while (tmp)
		{
			tmp->order = i;
			tmp = tmp->next;
			i++;
		}
	}
}

void	get_index_stack(t_process_params *params)
{
	t_stack	*tmp;

	if (params->stack_a && *(params->stack_a))
	{
		tmp = *(params->stack_a);
		while (tmp)
		{
			tmp->index = -1;
			tmp = tmp->next;
		}
	}
	get_index(params, stack_size(*(params->stack_a)));
	get_index_order(params);
}
