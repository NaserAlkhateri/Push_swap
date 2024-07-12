/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:30:33 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 00:03:29 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_lst_checker(t_stack *lst, long new_value)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		if (lst->value == new_value)
		{
			return (1);
		}
		lst = lst->next;
	}
	if (lst->value == new_value)
	{
		return (1);
	}
	return (0);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
		new->prev = temp;
	}
}

t_stack	*ft_lstnew(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->direction = 0;
	node->above_middle = 0;
	node->index = -1;
	node->cost = 0;
	node->target = NULL;
	return (node);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	if (*lst)
	{
		(*lst)->prev = new;
	}
	*lst = new;
}
