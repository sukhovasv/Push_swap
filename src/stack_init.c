/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:31:02 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 18:34:16 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_stack(char **elements)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 0;
	while (elements[i])
	{
		push(&a, ft_atoi(elements[i]));
		i++;
	}
	return (a);
}

t_stack	*parse_single_arg(char *arg)
{
	char	**elements;
	t_stack	*a;

	elements = ft_split(arg, ' ');
	if (!elements)
	{
		ft_printf("Error\n");
		return (NULL);
	}
	if (!check_for_numeric_one_arg(elements)
		|| !check_for_limits_one_arg(elements)
		|| !check_for_duplicates_one_arg(elements))
	{
		ft_printf("Error\n");
		free_split(elements);
		return (NULL);
	}
	a = initialize_stack(elements);
	free_split(elements);
	return (a);
}

t_stack	*parse_multiple_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	if (!check_for_numeric(argv) || !check_for_limits(argv)
		|| !check_for_duplicates(argv))
	{
		ft_printf("Error\n");
		return (NULL);
	}
	while (i < argc)
	{
		push(&a, ft_atoi(argv[i]));
		i++;
	}
	return (a);
}

t_stack	*stack_init(int argc, char **argv)
{
	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		return (parse_single_arg(argv[1]));
	else
		return (parse_multiple_args(argc, argv));
}
