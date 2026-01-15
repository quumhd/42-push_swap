/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:42:01 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/15 16:16:52 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_dublicate(int argc, int *stack_a)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		while (j < i)
			if (stack_a[j] == stack_a[i])
				return (1);
		j = 0;
		i++;
	}
	return (0);
}

t_stack	fill_stack_a(t_stack stack_a, char **argv)
{
	int		index;
	t_node	*node;

	while(argv[index])
	{
				
		index++;
	}
}

int	main(int argc, char **argv)
{
	// t_stack	stack_a;
	// t_stack	stack_b;
	// 
	char **input;
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = &argv[1];
	if (is_argv_valid(argc, input) == 0)
		return (put_error("Error\n"), 1);
	put_error("passed\n");
	return (0);
}
