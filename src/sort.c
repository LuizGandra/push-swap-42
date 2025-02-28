/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:16:25 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 15:37:13 by lcosta-g         ###   ########.fr       */
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

	// * STEP 1: Send Everything to Stack B
	fill_stack_b(&size);
	// * STEP 2: Sort the 3 Numbers Left in Stack A
	sort_three();
	stack_b = *get_stack_b();
	while (stack_size(stack_b) > 0)
	{
		// * STEP 3: Calculating Positions
		calculate_positions();
		// * STEP 4: Calculating the Cheapest Action Cost
		calculate_costs();
		// * STEP 5: Execute the Chosen Sequence of Actions
		execute_cheapest_sequence();
		stack_b = *get_stack_b();
	}
	// * STEP 6: Rotate Stack A to the Right Position
	stack_a = *get_stack_a();
	while (stack_a->sorted_i != 1)
	{
		ra();
		stack_a = *get_stack_a();
	}
}
