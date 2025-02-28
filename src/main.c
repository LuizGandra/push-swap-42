/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:32:49 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 15:38:41 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO remove
// void	check_stack(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("	- value: %i, sorted_i: %i, pos: %i, target_pos: %i, cost_a: %i, cost_b: %i\n", stack->value, stack->sorted_i, stack->pos, stack->target_pos, stack->cost_a, stack->cost_b);
// 		stack = stack->next;
// 	}
// }

// TODO remove
void	check_stack(t_stack *stack)
{
	ft_printf("Stack:\n");
	while (stack)
	{
		if (stack->next)
			ft_printf("%d, ", stack->value);
		else
			ft_printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!read_args(argc - 1, &argv[1]))
		throw_error();
	if (!stack_is_sorted(*get_stack_a()))
	{
		set_sorted_index();
		sort_stack();
	}
	check_stack(*get_stack_a());
	clean_stacks();
	return (EXIT_SUCCESS);
}
