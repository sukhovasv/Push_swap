/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:32:33 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 16:42:30 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack_process(t_stack_process **process)
{
	*process = malloc(sizeof(t_stack_process));
	if (*process == NULL)
		return ;
	(*process)->processed = 0;
	(*process)->moved = 0;
	(*process)->total = 0;
}

void	initialize_process_params(t_process_params *params)
{
	if (params == NULL)
		return ;
	initialize_stacks(params);
	if (!params->stack_a || !params->stack_b)
	{
		release_all_resources(params);
		return ;
	}
	initialize_stack_processes(params);
	if (!params->process_a || !params->process_b)
	{
		release_all_resources(params);
		return ;
	}
	initialize_other_fields(params);
}

void	initialize_stacks(t_process_params *params)
{
	params->stack_a = malloc(sizeof(t_stack *));
	if (params->stack_a == NULL)
	{
		return ;
	}
	*(params->stack_a) = NULL;
	params->stack_b = malloc(sizeof(t_stack *));
	if (params->stack_b == NULL)
	{
		free(params->stack_a);
		params->stack_a = NULL;
		return ;
	}
	*(params->stack_b) = NULL;
}

void	initialize_stack_processes(t_process_params *params)
{
	initialize_stack_process(&params->process_a);
	if (params->process_a == NULL)
		return ;
	initialize_stack_process(&params->process_b);
	if (params->process_b == NULL)
		return ;
}

void	initialize_other_fields(t_process_params *params)
{
	params->step = 0;
	params->max_steps = 0;
}
