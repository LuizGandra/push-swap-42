/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:32:49 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/26 18:22:16 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO remove
void	check_stack(void)
{
	t_stack	*stack_a;
	
	stack_a = *get_stack_a();
	ft_printf("Stack A:\n");
	while (stack_a)
	{
		if (stack_a->next)
			ft_printf("%d, ", stack_a->value);
		else
			ft_printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
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
	check_stack();
	clean_stacks();
	return (EXIT_SUCCESS);
}
