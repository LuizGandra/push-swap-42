/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:25:31 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/27 15:56:33 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_zero(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (n[i++] != '0')
			return (0);
	}
	return (1);
}

int is_same_sign(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}

void	throw_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	clean_stacks();
	exit(EXIT_FAILURE);
}

void	clean_stacks(void)
{
	t_stack **stack_a;
	t_stack **stack_b;
	
	stack_a = get_stack_a();
	stack_b = get_stack_b();
	if (stack_a && *stack_a)
		stack_clear(stack_a);
	if (stack_b && *stack_b)
		stack_clear(stack_b);
}
