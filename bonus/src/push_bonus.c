/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:38:46 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/01 12:53:41 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	push(t_stack **s_receiver, t_stack **s_sender);

void	pa(void)
{
	push(get_stack_a(), get_stack_b());
}

void	pb(void)
{
	push(get_stack_b(), get_stack_a());
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
