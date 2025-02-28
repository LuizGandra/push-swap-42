/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:58:56 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 15:35:24 by lcosta-g         ###   ########.fr       */
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
	if (*size % 2 == 0)
		target_size = middle_i + 1;
	else
		target_size = middle_i + 2;
	while (*size > target_size)
	{
		stack_a = *get_stack_a();
		if (stack_a->sorted_i < middle_i)
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
	t_stack	*highest_i;

	stack_a = *get_stack_a();
	stack_b = *get_stack_b();
	set_stack_positions(stack_a);
	set_stack_positions(stack_b);
	highest_i = get_highest_sorted_i_node(stack_a);
	while (stack_b)
	{
		stack_a = *get_stack_a();
		target = highest_i;
		while (stack_a)
		{
			if ((stack_a->sorted_i < target->sorted_i)
				&& (stack_a->sorted_i > stack_b->sorted_i))
				target = stack_a;
			stack_a = stack_a->next;
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
	{
		if (cheapest_node->cost_a > 0)
		{
			ra();
			cheapest_node->cost_a--;
		}
		else
		{
			rra();
			cheapest_node->cost_a++;
		}
	}
	while (cheapest_node->cost_b)
	{
		if (cheapest_node->cost_b > 0)
		{
			rb();
			cheapest_node->cost_b--;
		}
		else
		{
			rrb();
			cheapest_node->cost_b++;
		}
	}
}
