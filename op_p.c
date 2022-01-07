/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:20:01 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:20:04 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_stk(t_stak **a, t_stak **b, t_stak *tmp)
{
	tmp = NULL;
	if (*b == NULL && *a)
	{
		*b = (t_stak *)malloc(sizeof(t_stak));
		(*b)->prv = NULL;
		(*b)->num = (*a)->num;
		(*b)->nxt = NULL;
		(*a) = (*a)->nxt;
		(*a)->prv = NULL;
	}
	else
	{
		if (*a)
		{
			tmp = (t_stak *)malloc(sizeof(t_stak));
			tmp->num = (*a)->num;
			tmp->nxt = NULL;
			tmp->prv = NULL;
			add_front(b, tmp);
			(*a) = (*a)->nxt;
		}
	}
}
