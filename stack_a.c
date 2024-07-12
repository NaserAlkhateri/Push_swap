/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:37:29 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 01:16:35 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_a(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = a;
	while (temp)
	{
		node_cost_a(temp, b, a);
		temp = temp->next;
	}
}

void	set_a_target(t_stack *a, t_stack *b)
{
	t_stack	*current;

	stack_indexing(a);
	stack_indexing(b);
	current = a;
	while (current)
	{
		if (current->value > get_max_value(b)
			|| current->value < get_min_value(b))
			current->target = max_node(b);
		else
			current->target = find_target(b, current->value, 0);
		current = current->next;
	}
}

static	void	rotate_a_top(t_stack **a, t_stack **b, t_stack *move_node)
{
	t_stack	*target_node;

	target_node = move_node->target;
	if (move_node->direction == 1)
	{
		if (target_node->index > 0)
			rr(a, b, 1);
		else
			rot_op(a, "ra\n", 3);
	}
	else if (move_node->direction == 2)
	{
		if (target_node->index > 0)
			rrr(a, b, 1);
		else
			rrot_op(a, "rra\n", 4);
	}
	else
	{
		if (!(move_node->above_middle))
			rot_op(a, "ra\n", 3);
		else
			rrot_op(a, "rra\n", 4);
	}
}

void	move_to_b(t_stack **a, t_stack **b, t_stack *move_node)
{
	t_stack	*target_node;

	target_node = move_node->target;
	while (move_node->index > 0)
	{
		rotate_a_top(a, b, move_node);
		stack_indexing(*a);
		stack_indexing(*b);
	}
	move_to_head(a, b, target_node, 0);
	push_op(a, b, "pb\n", 3);
	stack_indexing(*a);
	stack_indexing(*b);
}
