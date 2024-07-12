/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:40:23 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 01:16:52 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost_b(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	temp = b;
	while (temp)
	{
		node_cost_b(temp, a, b);
		temp = temp->next;
	}
}

static	void	rotate_b_top(t_stack **a, t_stack **b, t_stack *move_node)
{
	t_stack	*target_node;

	target_node = move_node->target;
	if (move_node->direction == 1)
	{
		if (target_node->index > 0)
			rr(a, b, 1);
		else
			rot_op(b, "rb\n", 3);
	}
	else if (move_node->direction == 2)
	{
		if (target_node->index > 0)
			rrr(a, b, 1);
		else
			rrot_op(b, "rrb\n", 4);
	}
	else
	{
		if (!(move_node->above_middle))
			rot_op(b, "rb\n", 3);
		else
			rrot_op(b, "rrb\n", 4);
	}
}

void	move_to_a(t_stack **a, t_stack **b, t_stack *move_node)
{
	t_stack	*target_node;

	target_node = move_node->target;
	while (move_node->index > 0)
	{
		rotate_b_top(a, b, move_node);
		stack_indexing(*a);
		stack_indexing(*b);
	}
	move_to_head(a, b, target_node, 1);
	push_op(b, a, "pa\n", 3);
	stack_indexing(*a);
	stack_indexing(*b);
}
