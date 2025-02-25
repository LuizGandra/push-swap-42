/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:32:49 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/25 19:51:33 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (EXIT_FAILURE);
	else
	{
		if (!read_args(argc - 1, &argv[1]))
			throw_error();
	}
	clean_stacks();
	return (EXIT_SUCCESS);
}
