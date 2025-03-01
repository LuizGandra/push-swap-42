/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:38:46 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 20:11:42 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	push(t_stack **s_receiver, t_stack **s_sender);

void	pa(void)
{
	if (push(get_stack_a(), get_stack_b()))
		ft_printf("pa\n");
}

void	pb(void)
{
	if (push(get_stack_b(), get_stack_a()))
		ft_printf("pb\n");
}

static int	push(t_stack **s_receiver, t_stack **s_sender)
{
	t_stack	*temp;

	if (!*s_sender)
		return (0);
	temp = (*s_sender)->next;
	(*s_sender)->next = *s_receiver ;
	*s_receiver = *s_sender;
	*s_sender = temp;
	return (1);
}
