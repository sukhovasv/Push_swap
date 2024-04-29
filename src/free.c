/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:13:02 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 15:12:38 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_stack_process(t_stack_process *process)
{
	if (process)
		free(process);
}

void	free_process_params(t_process_params *params)
{
	if (params)
	{
		if (params->stack_a)
		{
			free_stack(*params->stack_a);
			free(params->stack_a);
		}
		if (params->stack_b)
		{
			free_stack(*params->stack_b);
			free(params->stack_b);
		}
		if (params->process_a)
			free_stack_process(params->process_a);
		if (params->process_b)
			free_stack_process(params->process_b);
	}
}

void	release_all_resources(t_process_params *params)
{
	if (params)
		free_process_params(params);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
