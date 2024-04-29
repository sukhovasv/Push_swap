/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:54:33 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 15:31:56 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_process_params	process_params;

	ft_memset(&process_params, 0, sizeof(process_params));
	if (initialize_all(&process_params, argc, argv))
		return (1);
	if (!is_sorted_ascending(*process_params.stack_a))
	{
		if ((stack_size(*process_params.stack_a)) <= 5)
			tiny_sort(&process_params);
		else
		{
			get_index_stack(&process_params);
			divide_between_stacks(&process_params);
			bit_by_bit_processing(&process_params);
		}
	}
	release_all_resources(&process_params);
	return (0);
}
