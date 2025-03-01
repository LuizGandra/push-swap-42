/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:38:10 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/01 12:41:55 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	reverse_rotate(t_stack **stack);

void	rra(void)
{
	reverse_rotate(get_stack_a());
}

void	rrb(void)
{
	reverse_rotate(get_stack_b());
}

void	rrr(void)
{
	reverse_rotate(get_stack_a());
	reverse_rotate(get_stack_b());
}

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*old_top;
	t_stack	*temp;
	t_stack	*ptr;

	if (!*stack || !(*stack)->next)
		return (0);
	ptr = *stack;
	old_top = ptr;
	while (ptr->next)
	{
		if (!ptr->next->next)
			temp = ptr;
		ptr = ptr->next;
	}
	temp->next = NULL;
	(*stack) = ptr;
	(*stack)->next = old_top;
	return (1);
}
