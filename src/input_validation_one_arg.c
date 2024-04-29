/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_one_arg.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:34:46 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 18:35:00 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_numeric_one_arg(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		if (arguments[i][j] == '-')
			j++;
		while (arguments[i][j])
		{
			if (!ft_isdigit((unsigned char)arguments[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_for_limits_one_arg(char **arguments)
{
	long long int	tmp;
	int				i;
	char			**nbr;

	nbr = arguments;
	i = 0;
	while (nbr[i])
	{
		tmp = ft_atoll(nbr[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_for_duplicates_one_arg(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i] != NULL)
	{
		j = i + 1;
		while (arguments[j] != NULL)
		{
			if (ft_strncmp(arguments[i], arguments[j], 11) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
