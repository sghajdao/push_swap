/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:13:27 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:13:34 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize(t_stak **a, t_stak **b, t_var *v, int min)
{
	int	idx;
	int	num;

	idx = get_idx((*a), min, 1);
	num = (list_size((*a)) / 2);
	if (num > idx)
		pick_case(a, b, ra(), v);
	else
		pick_case(a, b, rra(), v);
}

void	case_with_10(t_stak **a, t_stak **b, int len, t_var *v)
{
	int		i;
	int		min;
	t_stak	*tmp1;
	t_stak	*tmp2;

	i = len;
	while (i > 3)
	{
		min = get_min(*a);
		tmp1 = (*a)->nxt;
		if ((*a)->num != min && tmp1 && tmp1->num == min)
			pick_case(a, b, sa(), v);
		while (min != (*a)->num)
			normalize(a, b, v, min);
		if (min == (*a)->num)
		{
			tmp2 = *a;
			pick_case(a, b, pb(), v);
			free(tmp2);
			i--;
		}
	}
}

void	sort_3(t_stak **a, t_stak **b, t_var *v, int op)
{
	pick_case(a, b, sa(), v);
	pick_case(a, b, op, v);
}

void	case_with_3(t_stak **a, t_stak **b, int len, t_var *v)
{
	t_stak	*tmp;
	int		min;

	tmp = ft_lst_bottom(*a);
	min = get_min(*a);
	while (check_sort(a, len) == 0)
	{
		if ((*a)->num < (*a)->nxt->num && tmp->num == min)
			pick_case(a, b, rra(), v);
		else if ((*a)->num > (*a)->nxt->num && tmp->num == min)
			sort_3(a, b, v, rra());
		else if ((*a)->nxt->num == min)
		{
			if ((*a)->num < tmp->num)
				pick_case(a, b, sa(), v);
			else if ((*a)->num > tmp->num)
				pick_case(a, b, ra(), v);
		}
		else if ((*a)->num == min && (*a)->nxt->num > tmp->num)
			sort_3(a, b, v, ra());
	}
}

void	sort_short(t_stak **a, t_stak **b, int len, t_var *v)
{
	t_stak	*tmp;

	tmp = NULL;
	if (len == 2 && (*a)->num > (*a)->nxt->num)
		pick_case(a, b, sa(), v);
	if (len <= 3)
		case_with_3(a, b, len, v);
	else if (len > 3)
	{
		case_with_10(a, b, len, v);
		case_with_3(a, b, 3, v);
		while ((*b))
		{
			tmp = *b;
			pick_case(a, b, pa(), v);
			free(tmp);
		}
		free_stk(b);
	}
	free_stk(a);
}
