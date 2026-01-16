/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:45:03 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/16 17:36:35 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
	int				number;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	int		size;
	t_node	*top;
}	t_stack;

void	put_error(char *s);
int		is_argv_valid(int argc, char **argv);
void	fill_stack_a(t_stack *stack_a, char **input);


t_node	*new_node(int number, int index);
void	add_back(t_stack *stack, t_node *to_add);
void	fill_stack_a(t_stack *stack_a, char **input);
void	print_stack(t_stack *stack);

void	sa_sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa_pb(t_stack *destination, t_stack *origin);
void	ra_rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra_rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
