/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:26:09 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 23:25:52 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	save_numbers(char *numbers[]);

int	read_args(int argc, char *args[])
{
	char	**str;
	int		i;
	int		is_valid;

	i = -1;
	while (++i < argc)
	{
		str = ft_split(args[i], ' ');
		if (!str)
			return (0);
		is_valid = save_numbers(str);
		ft_clean_mem_grid(str);
		if (!is_valid)
			return (0);
	}
	return (1);
}

static int	save_numbers(char *numbers[])
{
	int			i;
	long long	n;
	t_stack		**stack_a;

	i = -1;
	stack_a = get_stack_a();
	while (numbers[++i])
	{
		if (!is_valid_number(numbers[i]))
			return (0);
		n = ft_atol(numbers[i]);
		if ((!n && !is_zero(numbers[i])) || (n > INT_MAX || n < INT_MIN))
			return (0);
		else if (!stack_search(*stack_a, n))
		{
			if (!stack_add(stack_a, n))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
