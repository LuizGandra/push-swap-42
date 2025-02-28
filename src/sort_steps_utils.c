/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_steps_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:00:58 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/27 23:39:59 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_b(int *size)
{
	pb();
	(*size)--;
}

void	set_stack_positions(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i++;
		stack = stack->next;
	}
}

int	calculate_cost_b(t_stack *stack_b)
{
	int		size_b;
	float	middle_i;

	size_b = stack_size(stack_b);
	middle_i = size_b / 2.0;
	if (stack_b->pos <= middle_i)
		return (stack_b->pos);
	else
		return (stack_b->pos - size_b);
}

int	calculate_cost_a(t_stack *stack_b, t_stack *stack_a)
{
	int		size_a;
	float	middle_i;

	size_a = stack_size(stack_a);
	middle_i = size_a / 2.0;
	if (stack_b->target_pos <= middle_i)
		return (stack_b->target_pos);
	else
		return (stack_b->pos - size_a);
}

t_stack	*get_cheapest_node(void)
{
	t_stack	*stack_b;
	t_stack	*cheapest_node;
	int	cheapest_cost;
	int	total_cost;

	stack_b = *get_stack_b();
	cheapest_node = NULL;
	cheapest_cost = INT_MAX;
	while (stack_b)
	{
		total_cost = ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b);
		if (!cheapest_node || total_cost < cheapest_cost)
		{
			cheapest_cost = total_cost;
			cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest_node);
}
