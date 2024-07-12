/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:07:42 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 01:04:00 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_stack(t_stack *a)
{
	t_stack	*temp;
	t_stack	*smallest_node;
	long	smallest;

	temp = a;
	smallest_node = a;
	if (!a)
		return (NULL);
	smallest = temp->value;
	while (temp)
	{
		if (temp->value < smallest)
		{
			smallest = temp->value;
			smallest_node = temp;
		}
		temp = temp->next;
	}
	return (smallest_node);
}

void	move_to_head(t_stack **a, t_stack **b, t_stack *target_node, int is_a)
{
	while (target_node->index > 0)
	{
		if (target_node->above_middle && is_a)
			rrot_op(a, "rra\n", 4);
		else if (is_a)
			rot_op(a, "ra\n", 3);
		else if ((target_node->above_middle && !is_a))
			rrot_op(b, "rrb\n", 4);
		else if (!is_a)
			rot_op(b, "rb\n", 3);
		stack_indexing(*a);
		stack_indexing(*b);
	}
}

void	reorder_stack_a(t_stack **a)
{
	t_stack	*smallest;

	if (!(*a))
		return ;
	smallest = min_stack(*a);
	if (smallest == *a)
		return ;
	while (smallest->index > 0)
	{
		if (!(smallest->above_middle))
			rot_op(a, "ra\n", 3);
		else
			rrot_op(a, "rra\n", 4);
		stack_indexing(*a);
	}
}
