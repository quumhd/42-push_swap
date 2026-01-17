/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:45:03 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/17 17:47:42 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				number;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

void	put_error(char *s);
int		is_argv_valid(int argc, char **argv);

t_node	*new_node(int number);
void	add_back(t_stack *stack, t_node *to_add);
int		fill_stack_a(t_stack *stack_a, char **input);
void	print_stack(t_stack *stack);

void	sa_sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa_pb(t_stack *destination, t_stack *origin);
void	ra_rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra_rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	add_indexing(t_stack *stack);
void	bubble_sort(int *numbers, int size);

void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif
