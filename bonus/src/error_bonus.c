/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:34:52 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/28 20:25:19 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	throw_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	clean_stacks();
	exit(EXIT_FAILURE);
}
