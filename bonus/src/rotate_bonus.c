/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:38:41 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 20:11:49 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	rotate(t_stack **stack);

void	ra(void)
{
	if (rotate(get_stack_a()))
		ft_printf("ra\n");
}

void	rb(void)
{
	if (rotate(get_stack_b()))
		ft_printf("rb\n");
}

void	rr(void)
{
	if (rotate(get_stack_a()) && rotate(get_stack_b()))
		ft_printf("rr\n");
}

static int	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*ptr;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	ptr = *stack;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = temp;
	return (1);
}
