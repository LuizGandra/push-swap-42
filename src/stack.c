/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:40:32 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 23:02:02 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_add(t_stack **stack, int n)
{
	static int	i;

	if (!*stack)
	{
		*stack = (t_stack *)malloc(sizeof(t_stack));
		if (!*stack)
			return (0);
		(*stack)->value = n;
		(*stack)->sorted_i = 0;
		(*stack)->pos = i++;
		(*stack)->target_pos = 0;
		(*stack)->cost_a = 0;
		(*stack)->cost_b = 0;
		(*stack)->next = NULL;
	}
	else
		stack_add(&(*stack)->next, n);
	return (1);
}

t_stack	*stack_search(t_stack *stack, int n)
{
	if (!stack)
		return (NULL);
	if (stack->value == n)
		return (stack);
	return (stack_search(stack->next, n));
}

void	stack_clear(t_stack **stack)
{
	if (!stack || !*stack)
		return ;
	if ((*stack)->next)
		stack_clear(&(*stack)->next);
	free(*stack);
}

int	stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (1 + stack_size(stack->next));
}
