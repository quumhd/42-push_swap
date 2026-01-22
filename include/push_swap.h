/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:45:03 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/23 00:40:12 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

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

int		ft_strcmp(const char *s1, const char *s2);
int		has_dup(char **input);
void	free_memory(t_stack *stack_a, t_stack *stack_b, char **input, int argc);
int		already_sorted(t_stack *stack_a);
char	**parse_input(int argc, char **arg, t_stack *stack_a, t_stack *stack_b);
void	choose_algorithm(int size, t_stack *stack_a, t_stack *stack_b);
int		fill_stack_a(t_stack *stack_a, char **input);
void	put_error(char *s);
void	put_str(char *s);
int		argv_valid(int argc, char **argv);
int		fits_in_int(char *s, int j);
void	add_indexing(t_stack *stack);
void	push_index(t_stack *a, t_stack *b, int target);
void	sort_three(t_stack *stack_a);
void	sort_low_numbers(t_stack *stack_a, t_stack *stack_b);
void	bubble_sort(int *numbers, int size);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
int		get_index(int *numbers, int to_find, int size);
void	add_indexing(t_stack *stack);
int		get_max_bits(int max_index);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	ra(t_stack *stack_a);
void	rra(t_stack *stack_a);

#endif
