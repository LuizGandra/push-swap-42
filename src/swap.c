/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:38:53 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/26 18:24:17 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **stack);

void	sa(void)
{
	if (swap(get_stack_a()))
		ft_printf("sa\n");
}

void	sb(void)
{
	if (swap(get_stack_b()))
		ft_printf("sb\n");
}

void	ss(void)
{
	if (swap(get_stack_a()) && swap(get_stack_b()))
		ft_printf("ss\n");
}

static int	swap(t_stack **stack)
{
	t_stack *temp;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	return (1);
}