/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:27:08 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/25 19:52:19 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// * LOAD STACK
int					read_args(int argc, char *args[]);

// * STACK
int					stack_add(t_stack **stack, int n);
t_stack				*stack_search(t_stack *stack, int n);
void				stack_clear(t_stack **stack);

// * STATICS
t_stack				**get_stack_a(void);
t_stack				**get_stack_b(void);

// * UTILS
int					is_zero(char *n);
void				throw_error(void);
void				clean_stacks(void);

#endif