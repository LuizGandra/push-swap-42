/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:06:09 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/11 16:36:47 by lcosta-g         ###   ########.fr       */
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
	if (!ft_strcmp(instruction, "sa\n"))
		sa();
	else if (!ft_strcmp(instruction, "sb\n"))
		sb();
	else if (!ft_strcmp(instruction, "ss\n"))
		ss();
	else if (!ft_strcmp(instruction, "pa\n"))
		pa();
	else if (!ft_strcmp(instruction, "pb\n"))
		pb();
	else if (!ft_strcmp(instruction, "ra\n"))
		ra();
	else if (!ft_strcmp(instruction, "rb\n"))
		rb();
	else if (!ft_strcmp(instruction, "rr\n"))
		rr();
	else if (!ft_strcmp(instruction, "rra\n"))
		rra();
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb();
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr();
	else
		return (0);
	return (1);
}
