/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:32:49 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 23:19:42 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!ft_strlen(argv[1]) || !read_args(argc - 1, &argv[1]))
		throw_error();
	if (!stack_is_sorted(*get_stack_a()))
	{
		set_sorted_index();
		sort_stack();
	}
	clean_stacks();
	return (EXIT_SUCCESS);
}
