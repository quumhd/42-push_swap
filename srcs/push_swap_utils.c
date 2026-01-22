/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:57:31 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/22 23:26:02 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fits_in_int(char *s, int j)
{
	if (j > 11)
		return (0);
	if (j == 10 && (ft_strncmp(s, "2147483647", 10) > 0))
		return (0);
	if (j == 11 && s[0] == '+')
		if (ft_strncmp(s, "+2147483647", 11) > 0)
			return (0);
	if (j == 11 && s[0] == '-')
		if (ft_strncmp(s, "-2147483648", 11) > 0)
			return (0);
	return (1);
}

int	argv_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc <= 1)
		exit (1);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (!fits_in_int(argv[i], j))
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int	already_sorted(t_stack *stack_a)
{
	t_node	*node;

	if (!stack_a || !stack_a->top)
		return (1);
	node = stack_a->top;
	while (node->next)
	{
		if (node->number > node->next->number)
			return (0);
		node = node->next;
	}
	return (1);
}

char	**parse_input(int argc, char ** argv, t_stack *stack_a, t_stack *stack_b)
{
	char	**input;

	input = NULL;
	if (!stack_a || !stack_b)
	{
		free_memory(stack_a, stack_b, input, argc);
		exit (1);
	}
	if (argc == 2 && argv[1][0])
		input = ft_split(argv[1], ' ');
	else if (argc > 2)
		input = &argv[1];
	else
	{
		free_memory(stack_a, stack_b, input, argc);
		exit (1);
	}
	if (argv_valid(argc, input) == 0 || has_dup(input) == 1)
	{	
		free_memory(stack_a, stack_b, input, argc);
		put_error("Error\n");
		exit (1);
	}
	return (input);
}

void	choose_algorithm(int size, t_stack *stack_a, t_stack *stack_b)
{
	if (size == 2)
		put_str("sa\n");
	if (size <= 5)
		sort_low_numbers(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
