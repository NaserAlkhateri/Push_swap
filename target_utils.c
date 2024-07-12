/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:14:25 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 01:27:59 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *a)
{
	long	cheapest;
	t_stack	*cheapest_node;

	if (!a)
		return (NULL);
	cheapest = a->cost;
	cheapest_node = a;
	while (a)
	{
		if (a->cost < cheapest)
		{
			cheapest = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	return (cheapest_node);
}

static	t_stack	*target_helper(t_stack *current, long *best_diff,
		t_stack *best_target, long diff)
{
	if (diff > 0 && diff < *best_diff)
	{
		*best_diff = diff;
		best_target = current;
	}
	return (best_target);
}

t_stack	*find_target(t_stack *stack, long value,
		int ascending)
{
	t_stack	*best_target;
	t_stack	*current;
	long	best_diff;
	long	diff;

	current = stack;
	best_diff = LONG_MAX;
	best_target = NULL;
	while (current)
	{
		diff = current->value - value;
		if (ascending)
			best_target = target_helper(current, &best_diff, best_target, diff);
		else
		{
			if (diff < 0 && (-diff) < best_diff)
			{
				best_diff = -diff;
				best_target = current;
			}
		}
		current = current->next;
	}
	return (best_target);
}

void	set_b_target(t_stack *a, t_stack *b)
{
	t_stack	*current;

	stack_indexing(a);
	stack_indexing(b);
	current = b;
	while (current)
	{
		if (current->value > get_max_value(a)
			|| current->value < get_min_value(a))
			current->target = min_stack(a);
		else
			current->target = find_target(a, current->value, 1);
		current = current->next;
	}
}
