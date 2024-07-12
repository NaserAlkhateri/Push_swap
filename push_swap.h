/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:18:19 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 19:02:19 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	long				value;
	int					index;
	int					cost;
	int					above_middle;
	int					direction;
	struct s_stack		*next;
	struct s_stack		*prev;
	struct s_stack		*target;
}	t_stack;

long	ft_atol(const char *str);
int		ft_isnum(char *c);
char	**ft_split(char const *s, char c);
void	exit_error(void);
void	check_input(char **argv, int argc);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int value);
void	ft_lstclear(t_stack **lst);
int		ft_isdigit(int c);
int		ft_lst_checker(t_stack *lst, long new_value);
void	swap_op(t_stack **x, char *stack_string, int write_size);
void	rrot_op(t_stack **x, char *stack_string, int write_size);
void	rot_op(t_stack **x, char *stack_string, int write_size);
void	push_op(t_stack **x, t_stack **y, char *stack_string, int write_size);
void	ss(t_stack **a, t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);
int		is_sorted(t_stack *a);
int		count_stack(t_stack *a);
void	sort_stack(t_stack **a);
t_stack	*max_node(t_stack *stack_a);
t_stack	*pop(t_stack **stack_x);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	stack_indexing(t_stack *stack_x);
void	set_a_target(t_stack *a, t_stack *b);
void	set_cost_a(t_stack *a, t_stack *b);
t_stack	*get_cheapest(t_stack *a);
void	reorder_stack_a(t_stack **a);
void	set_cost_b(t_stack *a, t_stack *b);
void	set_b_target(t_stack *a, t_stack *b);
t_stack	*find_target(t_stack *stack, long value, int ascending);
void	move_to_a(t_stack **a, t_stack **b, t_stack *move_node);
void	move_to_b(t_stack **a, t_stack **b, t_stack *move_node);
void	sort_three(t_stack **a);
long	get_min_value(t_stack *stack_x);
long	get_max_value(t_stack *stack_x);
t_stack	*min_stack(t_stack *a);
t_stack	*init_stack(char **argv, int flag, int i);
void	move_to_head(t_stack **a, t_stack **b, t_stack *target_node, int is_a);
void	node_cost_a(t_stack *curr_a_node, t_stack *b, t_stack *a);
void	node_cost_b(t_stack *curr_b_node, t_stack *a, t_stack *b);
int		ft_max(int x, int y);
#endif