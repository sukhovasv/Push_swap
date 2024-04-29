/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:01 by ssukhova          #+#    #+#             */
/*   Updated: 2024/04/29 17:13:41 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted_ascending(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL || stack->next == NULL)
		return (true);
	current = stack;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_sorted_descending(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL || stack->next == NULL)
		return (true);
	current = stack;
	while (current->next != NULL)
	{
		if (current->value < current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}

int	get_max_steps(t_stack **stack)
{
	t_stack	*head;
	int		max;
	int		max_steps;

	if (!stack || !*stack)
		return (0);
	head = *stack;
	max = head->index;
	max_steps = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_steps) != 0)
		max_steps++;
	return (max_steps);
}
/*void print_stack(t_stack *stack)
{
    if (!stack) {
        //ft_printf("Stack is empty.\n");
        return;
    }
    while (stack)
    {
        ft_printf("%d", stack->value);
        if (stack->next != NULL)
            ft_printf(" ");
        stack = stack->next;
    }
    ft_printf("\n");
}*/
