/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:27:27 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 16:13:56 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (1 + stack_size(stack->next));
}

int	stack_is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	if (stack->value > stack->next->value)
		return (0);
	return (stack_is_sorted(stack->next));
}

void	set_sorted_index(void)
{
	int		i;
	int		size;
	t_stack	*stack_a;
	t_stack	*smallest;

	i = 0;
	size = stack_size(*get_stack_a());
	while (i < size)
	{
		stack_a = *get_stack_a();
		smallest = NULL;
		while (stack_a)
		{
			if (stack_a->sorted_i == 0 && (!smallest
					|| stack_a->value < smallest->value))
				smallest = stack_a;
			stack_a = stack_a->next;
		}
		if (smallest)
			smallest->sorted_i = ++i;
	}
}

t_stack	*get_highest_sorted_i_node(t_stack *stack)
{
	t_stack	*highest_i;

	highest_i = NULL;
	while (stack)
	{
		if (!highest_i || stack->sorted_i > highest_i->sorted_i)
			highest_i = stack;
		stack = stack->next;
	}
	return (highest_i);
}

t_stack	*get_lowest_sorted_i_node(t_stack *stack)
{
	t_stack	*lowest;

	lowest = NULL;
	while (stack)
	{
		if (!lowest || stack->sorted_i < lowest->sorted_i)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}
