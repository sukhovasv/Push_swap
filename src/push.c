/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:13:33 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 15:33:52 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	if (*b)
	{
		stack_push(a, b);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b)
{
	if (*a)
	{
		stack_push (b, a);
		write(1, "pb\n", 3);
	}
}
