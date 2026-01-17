/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:52:14 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/17 14:29:29 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int number)
{
	t_node	*new_node;

	new_node = malloc (sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	add_back(t_stack *stack, t_node *to_add)
{
	t_node	*list;

	if (!stack)
		return ;
	if (stack->top == NULL)
	{
		stack->top = to_add;
		return ;
	}
	list = stack->top;
	while (list->next)
		list = list->next;
	list->next = to_add;
}

int	fill_stack_a(t_stack *stack_a, char **input)
{
	int		index;
	int		number;
	t_node	*node;

	index = 0;
	while (input[index])
	{
		number = ft_atoi(input[index]);
		node = new_node(number);
		if (!node)
			return (0);
		add_back(stack_a, node);
		index++;
	}
	return (index);
}

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node != NULL)
	{
		printf("%d: %d\n", node->index, node->number);
		node = node->next;
	}
}
