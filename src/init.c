/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:45:47 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 16:45:55 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_all(t_process_params *process_params, int argc, char **argv)
{
	initialize_process_params(process_params);
	if (process_params->process_a == NULL || process_params->process_b == NULL)
	{
		release_all_resources(process_params);
		return (1);
	}
	*process_params->stack_a = stack_init(argc, argv);
	if (!(*process_params->stack_a))
	{
		release_all_resources(process_params);
		return (1);
	}
	*process_params->stack_b = NULL;
	return (0);
}
