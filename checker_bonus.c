/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 01:20:04 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 19:01:55 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	exit_free(t_stack **a, t_stack **b, char *line, int flag)
{
	if (flag == 1)
		write(1, "OK\n", 3);
	else if (flag == 2)
		write(1, "KO\n", 3);
	else if (flag == 3)
		write(2, "Error\n", 6);
	if (line)
		free(line);
	line = NULL;
	ft_lstclear(a);
	ft_lstclear(b);
	exit(0);
}

int	input_operations(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		swap_op(a, "", 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap_op(b, "", 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(a, b, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push_op(b, a, "", 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push_op(a, b, "", 0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		rot_op(a, "", 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rot_op(b, "", 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rrot_op(a, "", 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrot_op(b, "", 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	get_input(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!input_operations(line, a, b))
			exit_free(a, b, line, 3);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	line = NULL;
	if (is_sorted(*a) && *b == NULL)
		exit_free(a, b, line, 1);
	else
		exit_free(a, b, line, 2);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	check_input(argv, argc);
	stack_a = init_stack(argv, 0, 0);
	get_input(&stack_a, &stack_b);
	return (0);
}
