/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:14:11 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:14:14 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stak **a, int len)
{
	t_stak	*tmp;

	if (list_size(*a) != len)
		return (0);
	tmp = *a;
	while (tmp && tmp->nxt)
	{
		if (tmp->nxt != NULL && (tmp->num < tmp->nxt->num))
			tmp = tmp->nxt;
		else
			return (0);
	}
	return (1);
}

void	check_dup(char **av)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (av[i])
	{
		dup = ft_strdup(av[i]);
		j = 0;
		while (av[j])
		{
			if (j == i)
				j++;
			else if (ft_strcmp(dup, av[j]) == 0)
			{
				ft_free_arg(&dup);
				ft_exit_ps("Error\n", 1);
			}
			else
				j++;
		}
		ft_free_arg(&dup);
		i++;
	}
}

int	check_overflow(char *arg)
{
	long long	tmp;

	tmp = ft_atoi(arg);
	if (tmp >= INT_MIN && tmp <= INT_MAX && ft_strlen(arg) < 12)
		return (1);
	else
		return (0);
}

int	check_numbers(char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		if (check_overflow(av[i]) == 0)
			ft_exit_ps("Error\n", 1);
		while (av[i][++j])
		{
			if (ft_isalpha(av[i][j]) == 1 || av[i][j] == '.'
			|| ((av[i][j]) == '-' && (av[i][j +1]) == '\0')
			|| ((av[i][j]) == '+' && (av[i][j +1]) == '\0'))
				ft_exit_ps("Error\n", 1);
		}
	}
	return (1);
}

int	check_pivot(t_stak *a, int pvt, int flag)
{
	while (a)
	{
		if (flag == 1)
		{
			if (a->num <= pvt)
				return (1);
			a = a->nxt;
		}
		if (flag == 2)
		{
			if (a->num == pvt)
				return (1);
			a = a->nxt;
		}
	}
	return (0);
}
