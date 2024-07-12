/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:42:08 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 01:17:05 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, int flag)
{
	int	size_a;
	int	size_b;

	size_a = count_stack(*a);
	size_b = count_stack(*b);
	if (size_a >= 2 && size_b >= 2)
	{
		swap_op(a, "", 0);
		swap_op(b, "", 0);
		if (flag)
			write(1, "ss\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	int	size_a;
	int	size_b;

	size_a = count_stack(*a);
	size_b = count_stack(*b);
	if (size_a >= 2 && size_b >= 2)
	{
		rot_op(a, "", 0);
		rot_op(b, "", 0);
		if (flag)
			write(1, "rr\n", 3);
	}
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	int	size_a;
	int	size_b;

	size_a = count_stack(*a);
	size_b = count_stack(*b);
	if (size_a >= 2 && size_b >= 2)
	{
		rrot_op(a, "", 0);
		rrot_op(b, "", 0);
		if (flag)
			write(1, "rrr\n", 4);
	}
}

t_stack	*pop(t_stack **stack_x)
{
	t_stack	*temp;

	temp = *stack_x;
	if (temp)
	{
		if ((*stack_x)->next != NULL)
		{
			*stack_x = (*stack_x)->next;
		}
		temp->next = NULL;
		temp->prev = NULL;
	}
	return (temp);
}

void	stack_indexing(t_stack *stack_x)
{
	int		middle;
	int		i;
	t_stack	*temp;

	temp = stack_x;
	i = 0;
	if (temp)
	{
		middle = (count_stack(temp) / 2);
		while (temp)
		{
			temp->index = i;
			if (i >= middle)
				temp->above_middle = 1;
			else
				temp->above_middle = 0;
			temp = temp->next;
			i++;
		}
	}
}
