/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:16:25 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 19:39:40 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(void);
static void	sort(int size);

void	sort_stack(void)
{
	t_stack	*stack_a;
	int		size;

	stack_a = *get_stack_a();
	size = stack_size(stack_a);
	if (size == 2)
		sa();
	else if (size == 3)
		sort_three();
	else
		sort(size);
}

static void	sort_three(void)
{
	t_stack	*stack_a;
	int		highest_i;

	stack_a = *get_stack_a();
	highest_i = get_highest_sorted_i_node(stack_a)->sorted_i;
	if (stack_is_sorted(stack_a))
		return ;
	if (stack_a->sorted_i == highest_i)
		ra();
	else if (stack_a->next->sorted_i == highest_i)
		rra();
	else if (stack_a->sorted_i > stack_a->next->sorted_i)
		sa();
	sort_three();
}

static void	sort(int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		middle_i;

	fill_stack_b(&size);
	sort_three();
	stack_b = *get_stack_b();
	while (stack_size(stack_b) > 0)
	{
		calculate_positions();
		calculate_costs();
		execute_cheapest_sequence();
		stack_b = *get_stack_b();
	}
	stack_a = *get_stack_a();
	middle_i = stack_size(stack_a) / 2;
	while (stack_a->sorted_i != 1)
	{
		if (stack_a->sorted_i > middle_i)
			ra();
		else
			rra();
		stack_a = *get_stack_a();
	}
}
