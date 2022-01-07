/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:15:11 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:15:14 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstnbr(t_stak **stk, int idx)
{
	t_stak	*tmp;
	int		i;

	i = 0;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (i == idx)
			return (tmp->num);
		i++;
		tmp = tmp->nxt;
	}
	return (1);
}

void	ft_lstswp(t_stak *x, t_stak *y)
{
	int	tmp;

	tmp = x->num;
	x->num = y->num;
	y->num = tmp;
}

t_stak	*ft_lstsort(t_stak *stk)
{
	t_stak	*base;
	t_stak	*tmp;
	t_stak	*cmp;

	base = NULL;
	base = stk;
	tmp = NULL;
	cmp = NULL;
	while (base->nxt)
	{
		cmp = base;
		tmp = base->nxt;
		while (tmp)
		{
			if (cmp->num > tmp->num)
				cmp = tmp;
			tmp = tmp->nxt;
		}
		ft_lstswp(base, cmp);
		base = base->nxt;
	}
	return (stk);
}
