/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:45:03 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/15 15:47:20 by jdreissi         ###   ########.fr       */
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
int		*fill_stack_a(int argc, char **argv, int *stack_a);

#endif
