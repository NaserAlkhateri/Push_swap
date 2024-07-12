/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:33:54 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/11 23:39:59 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 1)
		return (0);
	check_input(argv, argc);
	stack_a = init_stack(argv, 0, 0);
	sort_stack(&stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
