/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:21:52 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/21 14:49:31 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int *numbers, int to_find, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (to_find == numbers[i])
			return (i);
		i++;
	}
	return (0);
}

void	bubble_sort(int *numbers, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if (numbers[j] > numbers[j + 1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	add_indexing(t_stack *stack)
{
	int		i;
	t_node	*node;
	int		*numbers;

	i = 0;
	node = stack->top;
	numbers = malloc(stack->size * sizeof(int));
	while (node)
	{
		numbers[i] = node->number;
		node = node->next;
		i++;
	}
	bubble_sort(numbers, stack->size);
	node = stack->top;
	while (node)
	{
		node->index = get_index(numbers, node->number, stack->size);
		node = node->next;
	}
	free (numbers);
}

int	get_max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while (max_index != 0)
	{
		max_index = max_index >> 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		bits;
	int		index;
	int		rotation;
	int		temp_stack_size;

	rotation = 0;
	index = 0;
	bits = get_max_bits(stack_a->size - 1);
	while (rotation < bits)
	{
		temp_stack_size = stack_a->size;
		while (index < temp_stack_size)
		{
			if (((stack_a->top->index >> rotation) & 1) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			index++;
		}
		index = 0;
		while (stack_b->top)
			pa(stack_a, stack_b);
		rotation++;
	}
}
