/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:26:21 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/22 22:59:59 by jdreissi         ###   ########.fr       */
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

void	push_index(t_stack *a, t_stack *b, int target)
{
	int		pos;
	t_node	*node;

	pos = 0;
	node = a->top;
	while (node)
	{
		if (node->index == target)
			break;
		node = node->next;
		pos++;
	}
	if (pos <= a->size / 2)
		while (a->top->index != target)
			ra(a);
	else
		while (a->top->index != target)
			rra(a);
	pb(b, a);
}
