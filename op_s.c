/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:20:46 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:20:49 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_stk(t_stak **top)
{
	int		i;
	int		j;
	t_stak	*tmp;

	tmp = NULL;
	if ((*top) && (*top)->nxt)
	{
		tmp = *top;
		i = (*top)->num;
		j = (*top)->nxt->num;
		tmp = *top;
		(*top)->num = j;
		tmp = *top;
		(*top)->nxt->num = i;
		(*top) = tmp;
	}
}
