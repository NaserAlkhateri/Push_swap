/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: {naser} <{naser}@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:18:39 by {naser}          #+#    #+#             */
/*   Updated: 2024/07/12 00:00:42 by {naser}         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ret_overflow(int sign)
{
	(void) sign;
	exit_error();
}

long	ft_atol(const char *str)
{
	int						sign;
	unsigned long long		result;
	int						digits;

	sign = 1;
	result = 0;
	digits = 1;
	while (*str && (*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = (result * 10) + *str - 48;
		if (result > 9223372036854775808ULL || digits > 19)
			return (ret_overflow(sign), 1);
		str++;
		if (result > 0)
			digits++;
	}
	return (result * sign);
}

static	char	*ft_isnum_helper(char *c)
{
	while (*c && (*c == ' ' || *c == '\t'))
		c++;
	if (*c && (*c == '-' || *c == '+'))
		c++;
	return (c);
}

int	ft_isnum(char *c)
{
	int	flag;

	flag = 0;
	c = ft_isnum_helper(c);
	while (*c)
	{
		if (*c >= '0' && *c <= '9')
			flag = 1;
		else if (*c == ' ' || *c == '\t')
		{
			while (*c && (*c == ' ' || *c == '\t'))
				c++;
			if (*c && (*c == '-' || *c == '+'))
			{
				c++;
				if (!ft_isdigit(*c))
					return (0);
			}
			continue ;
		}
		else
			return (0);
		c++;
	}
	return (flag);
}

void	check_input(char **argv, int argc)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (ft_isnum(argv[i]) == 0)
			exit_error();
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			exit_error();
		i++;
	}
}
