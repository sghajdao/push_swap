/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:20:16 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:20:21 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stak	*rr_swap(t_stak *top, t_stak *tmp)
{
	while (top->nxt)
		top = top->nxt;
	tmp->num = top->num;
	tmp->nxt = NULL;
	tmp->prv = NULL;
	return (tmp);
}

void	rr_bottom(t_stak **top)
{
	while ((*top))
	{
		if ((*top)->nxt->nxt == NULL)
			break ;
		*top = (*top)->nxt;
	}
	free((*top)->nxt);
	(*top)->nxt = NULL;
}

void	rr_stk(t_stak **top, t_stak *tmp)
{
	t_stak	*a;

	a = NULL;
	tmp = NULL;
	if (*top)
	{
		tmp = (t_stak *)malloc(sizeof(t_stak));
		if (tmp == NULL)
			return ;
		tmp = rr_swap(*top, tmp);
		a = *top;
		rr_bottom(top);
		*top = a;
		add_front(top, tmp);
	}
}

void	r_stk(t_stak **top)
{
	if (*top)
	{
		*top = (*top)->nxt;
		add_back_r(top);
	}
}
