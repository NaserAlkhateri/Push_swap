/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:58:20 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 01:15:27 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_op(t_stack **x, char *stack_string, int write_size)
{
	t_stack	*first;
	t_stack	*second;

	if (*x && (*x)->next)
	{
		first = *x;
		second = (*x)->next;
		first->index = 1;
		second->index = 0;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->prev = NULL;
		second->next = first;
		first->prev = second;
		*x = second;
		if (write_size)
			write(1, stack_string, write_size);
	}
}

void	push_op(t_stack **x, t_stack **y, char *stack_string, int write_size)
{
	t_stack	*first;
	int		count;

	count = count_stack(*x);
	first = NULL;
	if (*x && count > 0)
	{
		first = pop(x);
		if (first)
		{
			ft_lstadd_front(y, first);
			if (write_size)
				write(1, stack_string, write_size);
		}
		if (count == 1)
		{
			*x = NULL;
		}
	}
}

void	rot_op(t_stack **x, char *stack_string, int write_size)
{
	t_stack	*first;

	first = NULL;
	if (*x && (*x)->next)
	{
		first = pop(x);
		ft_lstadd_back(x, first);
		if (write_size)
			write(1, stack_string, write_size);
	}
}

void	rrot_op(t_stack **x, char *stack_string, int write_size)
{
	t_stack	*last;
	t_stack	*new_last;

	last = NULL;
	new_last = NULL;
	if (*x && (*x)->next)
	{
		last = ft_lstlast(*x);
		new_last = last->prev;
		new_last->next = NULL;
		last->prev = NULL;
		(*x)->prev = last;
		last->next = *x;
		*x = last;
		if (write_size)
			write(1, stack_string, write_size);
	}
}
