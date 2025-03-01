/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:50:15 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 23:26:36 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (EXIT_FAILURE);
	if (!read_args(argc - 1, &argv[1]))
		throw_error();
	if (!stack_is_sorted(*get_stack_a()))
	{
		set_sorted_index();
		// TODO wait and read instructions on the standard input
	}
	else
		ft_printf("OK\n");
	clean_stacks();
	return (EXIT_SUCCESS);
}
