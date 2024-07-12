/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:19:29 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 00:25:20 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}

static	int	count_moves(t_stack *x, t_stack *curr_node)
{
	if (!curr_node->above_middle)
		return (curr_node->index);
	else
		return (count_stack(x) - curr_node->index);
}

void	node_cost_a(t_stack *curr_a_node, t_stack *b, t_stack *a)
{
	int	movements;
	int	direction_flag;

	movements = 0;
	direction_flag = 0;
	if (curr_a_node->above_middle && curr_a_node->target->above_middle)
		direction_flag = 2;
	else if (!curr_a_node->above_middle && !curr_a_node->target->above_middle)
		direction_flag = 1;
	if (direction_flag == 1)
		movements += ft_max(curr_a_node->index, curr_a_node->target->index);
	else if (direction_flag == 2)
		movements += ft_max(count_stack(a) - curr_a_node->index,
				count_stack(b) - curr_a_node->target->index);
	else
	{
		movements += count_moves(a, curr_a_node);
		movements += count_moves(b, curr_a_node->target);
	}
	curr_a_node->cost = movements;
	curr_a_node->direction = direction_flag;
}

void	node_cost_b(t_stack *curr_b_node, t_stack *a, t_stack *b)
{
	int	movements;
	int	direction_flag;

	movements = 0;
	direction_flag = 0;
	if (curr_b_node->above_middle && curr_b_node->target->above_middle)
		direction_flag = 2;
	else if (!curr_b_node->above_middle && !curr_b_node->target->above_middle)
		direction_flag = 1;
	if (direction_flag == 1)
		movements += ft_max(curr_b_node->index, curr_b_node->target->index);
	else if (direction_flag == 2)
		movements += ft_max(count_stack(b) - curr_b_node->index,
				count_stack(a) - curr_b_node->target->index);
	else
	{
		movements += count_moves(b, curr_b_node);
		movements += count_moves(a, curr_b_node->target);
	}
	curr_b_node->cost = movements;
	curr_b_node->direction = direction_flag;
}
