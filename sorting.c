/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 19:00:19 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 01:14:25 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = max_node(*a);
	if (*a == biggest)
		rot_op(a, "ra\n", 3);
	else if ((*a)->next == biggest)
		rrot_op(a, "rra\n", 4);
	else if ((*a)->value > (*a)->next->value)
		swap_op(a, "sa\n", 3);
	if (is_sorted(*a) == 1)
		return ;
	else
		sort_three(a);
}

static	void	move_smallest(t_stack **a, t_stack **b)
{
	t_stack	*smallest;

	smallest = min_stack(*a);
	while (smallest && smallest->index > 0)
	{
		if (smallest->above_middle)
			rrot_op(a, "rra\n", 4);
		else
			rot_op(a, "ra\n", 3);
		stack_indexing(*a);
	}
	push_op(a, b, "pb\n", 3);
	smallest = NULL;
}

static	void	sort_big(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = NULL;
	push_op(a, b, "pb\n", 3);
	push_op(a, b, "pb\n", 3);
	while (count_stack(*a) > 3)
	{
		set_a_target(*a, *b);
		set_cost_a(*a, *b);
		cheapest_node = get_cheapest(*a);
		move_to_b(a, b, cheapest_node);
	}
	sort_three(a);
	while (*b)
	{
		set_b_target(*a, *b);
		set_cost_b(*a, *b);
		cheapest_node = get_cheapest(*b);
		move_to_a(a, b, cheapest_node);
	}
	reorder_stack_a(a);
}

void	sort_four_five(t_stack **a, t_stack **b, int count)
{
	if (*a)
	{
		stack_indexing(*a);
		move_smallest(a, b);
		if (*a && count == 4)
		{
			sort_three(a);
			push_op(b, a, "pa\n", 3);
		}
		else if (*a && count == 5)
		{
			stack_indexing(*a);
			move_smallest(a, b);
			sort_three(a);
			push_op(b, a, "pa\n", 3);
			push_op(b, a, "pa\n", 3);
		}
	}
}

void	sort_stack(t_stack **a)
{
	t_stack	*b;
	int		count;

	b = NULL;
	count = count_stack(*a);
	if (is_sorted(*a))
		return ;
	if (count == 2)
		swap_op(a, "sa\n", 3);
	else if (count == 3)
		sort_three(a);
	else if (count == 4 || count == 5)
	{
		sort_four_five(a, &b, count);
	}
	else
		sort_big(a, &b);
}
