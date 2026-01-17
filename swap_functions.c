/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:04 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/16 17:59:05 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack *stack)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*temp;

	if (!stack->top)
		return ;
	first_node = stack->top;
	second_node = first_node->next;
	temp = first_node;
	first_node->next = second_node->next;
	second_node->next = temp;
	stack->top = second_node;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa_sb(stack_a);
	sa_sb(stack_b);
}

void	pa_pb(t_stack *destination, t_stack *origin)
{
	t_node	*move;
	t_node	*temp;

	if (!origin->top)
		return ;
	move = origin->top;
	origin->top = move->next;
	temp = destination->top;
	destination->top = move;
	move->next = temp;
}

void	ra_rb(t_stack *stack)
{
	t_node	*move;
	t_node	*temp;

	if (!stack->top)
		return ;
	move = stack->top;
	stack->top = move->next;
	temp = move;
	while (temp->next)
		temp = temp->next;
	temp->next = move;
	move->next = NULL;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra_rb(stack_a);
	ra_rb(stack_b);
}

void	rra_rrb(t_stack *stack)
{
	t_node	*move;
	t_node	*temp;

	if (!stack->top)
		return ;
	temp = stack->top;
	while (temp->next->next)
		temp = temp->next;
	move = temp->next;
	temp->next = NULL;
	move->next = stack->top;
	stack->top = move;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra_rrb(stack_a);
	rra_rrb(stack_b);
}
