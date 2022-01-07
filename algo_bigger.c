/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:10:44 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:12:28 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_sort(t_stak **a, t_stak **b, int len, t_var *v)
{
	int		i;
	int		pvt;
	t_stak	*tmp1;

	i = len;
	while (i >= (len / 30))
	{
		tmp1 = ft_lst_dup(*a);
		pvt = get_pivot(tmp1);
		while (check_pivot((*a), pvt, 1) && (*a))
		{
			if ((*a)->num <= pvt)
			{
				pick_case(a, b, pb(), v);
				i--;
			}
			else
				normalize_a(a, b, v, pvt);
		}
		free_stk(&tmp1);
	}
}

void	second_sort(t_stak **a, t_stak **b, int len, t_var *v)
{
	int		min;
	t_stak	*tmp;

	tmp = NULL;
	while (*a && !check_sort(a, len))
	{
		min = get_min(*a);
		tmp = (*a)->nxt;
		if ((*a)->num != min && tmp && tmp->num == min)
			pick_case(a, b, sa(), v);
		while (list_size(*a) && check_pivot((*a), min, 1))
		{
			if ((*a)->num == min)
			{
				tmp = *a;
				pick_case(a, b, pb(), v);
				free(tmp);
				len--;
			}
			else
				normalize_a(a, b, v, min);
		}
	}
}

void	third_sort(t_stak **a, t_stak **b, int max, t_var *v)
{
	t_stak	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = get_max(*b);
		while (check_pivot((*b), max, 2))
		{
			max = get_max(*b);
			tmp = (*b)->nxt;
			while ((*b)->num != max && tmp && tmp->num == max)
				pick_case(a, b, sb(), v);
			while (((*b)->num != max) && *b)
				normalize_b(a, b, v, max);
			while (*b && (*b)->num == max)
			{
				tmp = *b;
				pick_case(a, b, pa(), v);
				max = get_max(*b);
				free(tmp);
			}
		}
	}
}

void	sort_bigger(t_stak **a, t_stak **b, int len, t_var *v)
{
	int	max;

	max = 0;
	first_sort(a, b, len, v);
	second_sort(a, b, len, v);
	third_sort(a, b, max, v);
	free_stk(a);
	free_stk(b);
}
