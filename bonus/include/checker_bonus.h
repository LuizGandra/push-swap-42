/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:27:08 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/03/01 13:17:45 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				sorted_i;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// * STATICS
t_stack				**get_stack_a(void);
t_stack				**get_stack_b(void);

// * LOAD STACK
int					read_args(int argc, char *args[]);

// * STACK
int					stack_add(t_stack **stack, int n);
t_stack				*stack_search(t_stack *stack, int n);
void				stack_clear(t_stack **stack);
int					stack_size(t_stack *stack);

// * utils
int					stack_is_sorted(t_stack *stack);
void				set_sorted_index(void);
void				clean_stacks(void);

// * INSTRUCTIONS
char				*read_instruction(void);
int					run_instruction(char *instruction);

// * PUSH
void				pa(void);
void				pb(void);

// * SWAP
void				sa(void);
void				sb(void);
void				ss(void);

// * ROTATE
void				ra(void);
void				rb(void);
void				rr(void);

// * REVERSE ROTATE
void				rra(void);
void				rrb(void);
void				rrr(void);

// * ERROR
void				throw_error(void);

// * UTILS
int					is_zero(char *n);
int					is_valid_number(char *str);

#endif