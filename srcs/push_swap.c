/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:42:01 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/23 15:07:31 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = NULL;
	temp = NULL;
	if (!stack)
		return ;
	if (!stack->top)
	{
		free (stack);
		return ;
	}
	node = stack->top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(stack);
}

void	free_memory(t_stack *stack_a, t_stack *stack_b, char **input, int argc)
{
	int	i;

	i = 0;
	if (input && argc == 2)
	{
		while (input[i])
		{
			free(input[i]);
			i++;
		}
		free(input);
	}
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
}

void	check_duplicates(t_stack *stack_a)
{
	int		i;
	int		j;
	t_node	*node;
	int		*numbers;

	i = -1;
	node = stack_a->top;
	numbers = malloc(stack_a->size * sizeof(int));
	while (node)
	{
		numbers[++i] = node->number;
		node = node->next;
	}
	i = 0;
	j = 0;
	while (i < stack_a->size)
	{
		while (j < i)
			if (numbers[j++] == numbers[i])
				put_error("Error\n");
		j = 0;
		i++;
	}
	free (numbers);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**input;

	input = NULL;
	stack_a = ft_calloc(1, sizeof(t_stack));
	stack_b = ft_calloc(1, sizeof(t_stack));
	input = parse_input(argc, argv, stack_a, stack_b);
	stack_a->size = fill_stack_a(stack_a, input);
	add_indexing(stack_a);
	check_duplicates(stack_a);
	if (already_sorted(stack_a) == 1)
		return (free_memory(stack_a, stack_b, input, argc), 1);
	choose_algorithm(stack_a->size, stack_a, stack_b);
	free_memory(stack_a, stack_b, input, argc);
	return (0);
}
