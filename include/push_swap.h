/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcosta-g <lcosta-g@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:27:08 by lcosta-g          #+#    #+#             */
/*   Updated: 2025/02/27 20:18:17 by lcosta-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
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

// * utils
int					stack_size(t_stack *stack);
int					stack_is_sorted(t_stack *stack);
void				set_sorted_index(void);
int					get_highest_sorted_i(t_stack *stack);

// * SORT
void				sort_stack(void);

// * SORT STEPS
void				fill_stack_b(int *size);
void				calculate_positions(void);
void				calculate_costs(void);
void				execute_cheapest_sequence(void);

// * utils
void				push_to_stack_b(int *size);
void				set_stack_positions(t_stack *stack);
int					calculate_cost_b(t_stack *stack_b);
int					calculate_cost_a(t_stack *stack_b, t_stack *stack_a);
t_stack				*get_cheapest_node(void);

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

// * UTILS
int					is_zero(char *n);
int					is_same_sign(int a, int b);
void				throw_error(void);
void				clean_stacks(void);

#endif