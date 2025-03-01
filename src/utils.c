/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:25:31 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 23:04:31 by lcosta-g         ###   ########.fr       */
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

int	is_same_sign(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	update_target(t_stack *stack_a, t_stack *stack_b, t_stack **target)
{
	if ((stack_a->sorted_i < (*target)->sorted_i)
		&& (stack_a->sorted_i > stack_b->sorted_i))
		*target = stack_a;
}

void	run_action(int *cost, char stack)
{
	if (*cost > 0)
	{
		if (stack == 'a')
			ra();
		else
			rb();
		(*cost)--;
	}
	else
	{
		if (stack == 'a')
			rra();
		else
			rrb();
		(*cost)++;
	}
}
