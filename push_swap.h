/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:45:03 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/15 16:18:28 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	put_error(char *s);
int		is_argv_valid(int argc, char **argv);
int		*fill_stack_a(int argc, char **argv, int *stack_a);

#endif
