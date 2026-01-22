/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:42:01 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/22 22:41:58 by jdreissi         ###   ########.fr       */
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

int	has_dup(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		while (j < i)
		{
			if (ft_strcmp(input[i], input[j]) == 0)
				return (1);
			j++;
		}
		j = 0;
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
	if (already_sorted(stack_a) == 1)
		exit (0);
	choose_algorithm(stack_a->size, stack_a, stack_b);
	free_memory(stack_a, stack_b, input, argc);
	return (0);
}
