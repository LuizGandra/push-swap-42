/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:06:09 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/01 13:32:45 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*read_instruction(void)
{
	char	*instruction;

	instruction = get_next_line(0);
	if (!instruction)
		return (NULL);
	return (instruction);
}

int	run_instruction(char *instruction)
{
	if (!ft_strncmp(instruction, "sa", 2))
		sa();
	else if (!ft_strncmp(instruction, "sb", 2))
		sb();
	else if (!ft_strncmp(instruction, "ss", 2))
		ss();
	else if (!ft_strncmp(instruction, "pa", 2))
		pa();
	else if (!ft_strncmp(instruction, "pb", 2))
		pb();
	else if (!ft_strncmp(instruction, "ra", 2))
		ra();
	else if (!ft_strncmp(instruction, "rb", 2))
		rb();
	else if (!ft_strncmp(instruction, "rr", 2))
		rr();
	else if (!ft_strncmp(instruction, "rra", 3))
		rra();
	else if (!ft_strncmp(instruction, "rrb", 3))
		rrb();
	else if (!ft_strncmp(instruction, "rrr", 3))
		rrr();
	else
		return (0);
	return (1);
}
