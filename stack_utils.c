/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:45:55 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/11 23:47:14 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	long	number;

	if (a)
	{
		number = a->value;
		while (a->next != NULL)
		{
			a = a->next;
			if (number > a->value)
			{
				return (0);
			}
			number = a->value;
		}
	}
	return (1);
}

int	count_stack(t_stack *a)
{
	int	count;

	count = 0;
	if (a)
	{
		while (a != NULL)
		{
			count++;
			a = a->next;
		}
	}
	return (count);
}

t_stack	*max_node(t_stack *stack_a)
{
	t_stack	*biggest;
	long	number;

	biggest = stack_a;
	if (stack_a)
	{
		number = biggest->value;
		while (stack_a->next != NULL)
		{
			stack_a = stack_a->next;
			if (number < stack_a->value)
			{
				number = stack_a->value;
				biggest = stack_a;
			}
		}
	}
	return (biggest);
}

long	get_max_value(t_stack *stack_x)
{
	t_stack	*max_n;

	max_n = max_node(stack_x);
	if (max_n)
		return (max_n->value);
	return (0);
}

long	get_min_value(t_stack *stack_x)
{
	t_stack	*min_n;

	min_n = min_stack(stack_x);
	if (min_n)
		return (min_n->value);
	return (0);
}
