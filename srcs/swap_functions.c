/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdreissi <jdreissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:48:04 by jdreissi          #+#    #+#             */
/*   Updated: 2026/01/22 23:31:38 by jdreissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*move;
	t_node	*temp;

	if (!stack_b->top)
		return ;
	move = stack_b->top;
	stack_b->top = move->next;
	temp = stack_a->top;
	stack_a->top = move;
	move->next = temp;
	stack_a->size = stack_a->size + 1;
	stack_b->size = stack_b->size - 1;
	put_str("pa\n");
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*move;
	t_node	*temp;

	if (!stack_a->top)
		return ;
	move = stack_a->top;
	stack_a->top = move->next;
	temp = stack_b->top;
	stack_b->top = move;
	move->next = temp;
	stack_b->size = stack_b->size + 1;
	stack_a->size = stack_a->size - 1;
	put_str("pb\n");
}

void	ra(t_stack *stack_a)
{
	t_node	*move;
	t_node	*temp;

	if (!stack_a->top)
		return ;
	move = stack_a->top;
	stack_a->top = move->next;
	temp = move;
	while (temp->next)
		temp = temp->next;
	temp->next = move;
	move->next = NULL;
	put_str("ra\n");
}

void	rra(t_stack *stack_a)
{
	t_node	*move;
	t_node	*temp;

	if (!stack_a->top)
		return ;
	temp = stack_a->top;
	while (temp->next->next)
		temp = temp->next;
	move = temp->next;
	temp->next = NULL;
	move->next = stack_a->top;
	stack_a->top = move;
	put_str("rra\n");
}
