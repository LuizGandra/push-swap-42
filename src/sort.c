/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:16:25 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/26 18:04:23 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(int size);
static void	sort(int size);

void	sort_stack(void)
{
	t_stack	*stack_a;
	int		size;

	stack_a = *get_stack_a();
	size = stack_size(stack_a);
	if (size == 2)
		sa();
	else if (size == 3)
		sort_three(size);
	else
		sort(size);
}

static void	sort_three(int size)
{
	t_stack	*stack_a;

	stack_a = *get_stack_a();
	if (stack_is_sorted(stack_a))
		return ;
	if (stack_a->sorted_i == size)
		ra();
	else if (stack_a->next->sorted_i == size)
		rra();
	else if (stack_a->sorted_i > stack_a->next->sorted_i)
		sa();
	sort_three(size);
}

// TODO
static void	sort(int size)
{
	(void)size;
}