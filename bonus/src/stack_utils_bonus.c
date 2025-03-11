/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:27:27 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/11 16:13:51 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	clean_stacks(void)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = get_stack_a();
	stack_b = get_stack_b();
	if (stack_a && *stack_a)
		stack_clear(stack_a);
	if (stack_b && *stack_b)
		stack_clear(stack_b);
}
