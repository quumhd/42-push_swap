/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:42:01 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/16 17:55:30 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	contains_dublicate(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		while (j < i)
		{
			if (ft_strncmp(input[i], input[j], ft_strlen(input[i])) == 0)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = &argv[1];
	if (is_argv_valid(argc, input) == 0 || contains_dublicate(input) == 1)
		return (put_error("Error\n"), 1);
	put_error("Input valid\n");
	fill_stack_a(stack_a, input);
	print_stack(stack_a);
	rra_rrb(stack_a);
	printf("\n");
	print_stack(stack_a);
	return (0);
}
