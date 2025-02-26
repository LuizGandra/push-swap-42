/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:56:15 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/26 12:14:10 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_sorted_index(int *arr, int n, int size);
static int	*copy_stack(t_stack *stack, int size);
static void	sort_array(int *arr, int size);

void	set_sorted_index(void)
{
	int		*temp;
	int		size;
	t_stack	*stack_a;

	stack_a = *get_stack_a();
	size = stack_size(stack_a);
	// * copy stack_a values to temp array
	temp = copy_stack(stack_a, size);
	if (!temp)
		throw_error();
	// * sort array
	sort_array(temp, size);
	// * set sorted_i for each stack_a node
	while (stack_a)
	{
		stack_a->sorted_i = get_sorted_index(temp, stack_a->value, size);
		stack_a = stack_a->next;
	}
	free(temp);
}

static int	get_sorted_index(int *arr, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (++i);
		i++;
	}
	return (-1);
}

static int	*copy_stack(t_stack *stack, int size)
{
	int	*temp;

	temp = (int *)malloc(sizeof(int) * size);
	if (!temp)
		return (NULL);
	while (stack)
	{
		temp[stack->pos] = stack->value;
		stack = stack->next;
	}
	return (temp);
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	temp;
	int	swap_count;

	swap_count = 1;
	while (swap_count)
	{
		i = 0;
		swap_count = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swap_count++;
			}
			i++;
		}
	}
}
