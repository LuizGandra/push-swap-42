/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 19:50:15 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/01 13:45:21 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char *argv[])
{
	char	*instruction;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (!ft_strlen(argv[1]) || !read_args(argc - 1, &argv[1]))
		throw_error();
	set_sorted_index();
	while (1)
	{
		instruction = read_instruction();
		if (!instruction)
			break ;
		if (!run_instruction(instruction))
			throw_error();
	}
	if (stack_is_sorted(*get_stack_a()) && !stack_size(*get_stack_b()))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean_stacks();
	return (EXIT_SUCCESS);
}
