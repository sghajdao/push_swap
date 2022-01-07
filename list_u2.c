/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_u2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:15:50 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:15:56 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stak	*ft_lst_dup(t_stak *stk)
{
	t_stak	*tmp1;
	t_stak	*tmp2;

	tmp1 = malloc(sizeof(t_stak));
	ft_bzero(tmp1, sizeof(t_stak));
	tmp2 = tmp1;
	while (stk)
	{
		tmp1->num = stk->num;
		if (stk->nxt)
		{
			tmp1->nxt = malloc(sizeof(t_stak));
			ft_bzero(tmp1->nxt, sizeof(t_stak));
			tmp1 = tmp1->nxt;
		}
		stk = stk->nxt;
	}
	tmp1 = tmp2;
	return (tmp1);
}

t_stak	*ft_lst_bottom(t_stak *a)
{
	t_stak	*tmp;

	tmp = a;
	while ((tmp)->nxt)
		(tmp) = (tmp)->nxt;
	return (tmp);
}
