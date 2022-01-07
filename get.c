/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:14:28 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:14:32 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_idx(t_stak *stk, int num, int flag)
{
	int	i;

	i = 1;
	if (flag == 1)
	{
		while (stk)
		{
			if (stk->num <= num)
				return (i);
			stk = stk->nxt;
			i++;
		}
	}
	if (flag == 2)
	{
		while (stk)
		{
			if (stk->num >= num)
				return (i);
			stk = stk->nxt;
			i++;
		}
	}
	return (-1);
}

int	get_pivot(t_stak *stk)
{
	t_stak	*tmp;
	int		len;
	int		pvt;

	pvt = 0;
	len = 0;
	tmp = NULL;
	len = list_size(stk);
	tmp = ft_lstsort(stk);
	if (len <= 10)
		pvt = ft_abs(len / 2);
	else if (len > 10 && len < 200)
		pvt = ft_abs(len / 4);
	else if (len >= 200)
		pvt = ft_abs(len / 8);
	return (ft_lstnbr(&tmp, pvt));
}

int	get_max(t_stak *stk)
{
	int		max;
	t_stak	*tmp;

	max = 0;
	tmp = NULL;
	if (stk)
	{
		max = stk->num;
		tmp = stk;
		while (stk)
		{
			if (stk->num >= max)
				max = stk->num;
			stk = stk->nxt;
		}
		stk = tmp;
	}
	return (max);
}

int	get_min(t_stak *stk)
{
	int	min;

	min = stk->num;
	while (stk)
	{
		if (stk->num < min)
			min = stk->num;
		stk = stk->nxt;
	}
	return (min);
}
