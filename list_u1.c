/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_u1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:15:32 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:15:35 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stk(t_stak **stk)
{
	t_stak	*tmp;

	if (*stk)
	{
		while (*stk)
		{
			tmp = (*stk)->nxt;
			free(*stk);
			*stk = NULL;
			(*stk) = tmp;
		}
		free(*stk);
		*stk = NULL;
	}
}

int	list_size(t_stak *a)
{
	int		len;

	len = 0;
	while (a)
	{
		len++;
		a = a->nxt;
	}
	return (len);
}

void	add_back(t_stak **top, t_stak *new)
{
	t_stak	*tmp;

	if (*top == NULL)
		*top = new;
	else
	{
		tmp = *top;
		while (tmp->nxt)
			tmp = tmp->nxt;
		tmp->nxt = new;
		new->prv = tmp;
	}
}

void	add_back_r(t_stak **top)
{
	t_stak	*tmp1;
	t_stak	*tmp2;

	tmp1 = NULL;
	tmp1 = *top;
	tmp2 = (*top)->prv;
	while (tmp1->nxt)
		tmp1 = tmp1->nxt;
	tmp1->nxt = tmp2;
	tmp1->nxt->prv = tmp1;
	tmp1->nxt->nxt = NULL;
}

void	add_front(t_stak **top, t_stak *new)
{
	new->nxt = (*top);
	new->prv = NULL;
	if ((*top) != NULL)
		(*top)->prv = new;
	(*top) = new;
}
