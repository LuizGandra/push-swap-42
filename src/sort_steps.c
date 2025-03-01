/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:58:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 19:12:29 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_sequence(t_stack *cheapest_node);

void	fill_stack_b(int *size)
{
	t_stack	*stack_a;
	int		middle_i;
	int		target_size;

	stack_a = *get_stack_a();
	middle_i = *size / 2;
	target_size = middle_i + 1;
	while (*size > target_size)
	{
		stack_a = *get_stack_a();
		if (stack_a->sorted_i <= middle_i)
			push_to_stack_b(size);
		else
			ra();
	}
	while (*size > 3)
		push_to_stack_b(size);
}

void	calculate_positions(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*target;

	stack_a = *get_stack_a();
	stack_b = *get_stack_b();
	set_stack_positions(stack_a);
	set_stack_positions(stack_b);
	while (stack_b)
	{
		stack_a = *get_stack_a();
		target = get_highest_sorted_i_node(stack_a);
		if (stack_b->sorted_i > target->sorted_i)
			target = get_lowest_sorted_i_node(stack_a);
		else
		{
			while (stack_a)
			{
				update_target(stack_a, stack_b, &target);
				stack_a = stack_a->next;
			}
		}
		stack_b->target_pos = target->pos;
		stack_b = stack_b->next;
	}
}

void	calculate_costs(void)
{
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = *get_stack_a();
	stack_b = *get_stack_b();
	size = stack_size(stack_b);
	while (stack_b)
	{
		stack_b->cost_b = calculate_cost_b(stack_b, size);
		stack_b->cost_a = calculate_cost_a(stack_b, stack_a);
		stack_b = stack_b->next;
	}
}

void	execute_cheapest_sequence(void)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node();
	if (is_same_sign(cheapest_node->cost_a, cheapest_node->cost_b))
	{
		while (cheapest_node->cost_a && cheapest_node->cost_b)
		{
			if (cheapest_node->cost_a > 0)
			{
				rr();
				cheapest_node->cost_a--;
				cheapest_node->cost_b--;
			}
			else
			{
				rrr();
				cheapest_node->cost_a++;
				cheapest_node->cost_b++;
			}
		}
	}
	finish_sequence(cheapest_node);
	pa();
}

static void	finish_sequence(t_stack *cheapest_node)
{
	while (cheapest_node->cost_a)
		run_action(&cheapest_node->cost_a, 'a');
	while (cheapest_node->cost_b)
		run_action(&cheapest_node->cost_b, 'b');
}
