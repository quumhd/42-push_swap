/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:42:01 by jdreissi          #+#    #+#             */
/*   Updated: 2025/12/15 16:30:09 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_stack_a(int argc, char **argv, int *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack_a = malloc (argc * sizeof (int));
	while (argv[j])
	{
		stack_a[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	// int	*stack_b;

	stack_a = NULL;
	if (is_argv_valid(argc, argv) == 0)
		return (put_error("Error\n"), 1);
	stack_a = fill_stack_a(argc, argv, stack_a);
	int i = 0;
	while (i < argc)
	{
		printf ("%d\n", stack_a[i]);
		i++;
	}
	return (0);
}
