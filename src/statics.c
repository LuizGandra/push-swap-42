/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:24:26 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 16:23:24 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**get_stack_a(void)
{
	static t_stack	*stack_a;

	return (&stack_a);
}

t_stack	**get_stack_b(void)
{
	static t_stack	*stack_b;

	return (&stack_b);
}
