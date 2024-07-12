/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:18:24 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 19:01:38 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

t_stack	*init_stack(char **argv, int flag, int i)
{
	char	**splitted;
	t_stack	*new_node;
	t_stack	*stack_a;

	stack_a = NULL;
	while (*argv)
	{
		i = 0;
		splitted = ft_split(*argv++, ' ');
		while (splitted[i] != NULL)
		{
			if (ft_isnum(splitted[i]))
			{
				if (ft_lst_checker(stack_a, ft_atol(splitted[i])) == 1)
					flag = 1;
				new_node = ft_lstnew(ft_atol(splitted[i]));
				ft_lstadd_back(&stack_a, new_node);
			}
			free(splitted[i++]);
		}
		free(splitted);
	}
	if (flag)
		return (ft_lstclear(&stack_a), exit_error(), NULL);
	return (stack_a);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	if (lst)
	{
		while (*lst != NULL)
		{
			temp = *lst;
			*lst = (*lst)->next;
			free(temp);
		}
	}
}
