/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:21:52 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/23 00:34:20 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_low_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	pushed;

	pushed = 0;
	if (stack_a->size == 5)
		push_index(stack_a, stack_b, pushed++);
	if (stack_a->size > 3)
		push_index(stack_a, stack_b, pushed);
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
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
