/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:13:48 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:13:53 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	next_next_case(t_stak **a, t_stak **b, int c, t_var *v)
{
	t_stak	*tmp;

	tmp = NULL;
	if (c == 7 && list_size(*b) > 1)
	{
		ft_putstr_fd("sb\n", v->fd);
		s_stk(b);
	}
	else if (c == 8 && list_size(*a) > 1)
	{
		ft_putstr_fd("sa\n", v->fd);
		s_stk(a);
	}
}

void	next_case(t_stak **a, t_stak **b, int c, t_var *v)
{
	t_stak	*tmp;

	tmp = NULL;
	if (c == 4)
	{
		ft_putstr_fd("pa\n", v->fd);
		p_stk(b, a, tmp);
		free(tmp);
	}
	else if (c == 5 && list_size(*b) > 1)
	{
		ft_putstr_fd("rb\n", v->fd);
		r_stk(b);
		free(tmp);
	}
	else if (c == 6 && list_size(*b) > 1)
	{
		ft_putstr_fd("rrb\n", v->fd);
		rr_stk(b, tmp);
		free(tmp);
	}
	else
		next_next_case(a, b, c, v);
}

void	pick_case(t_stak **a, t_stak **b, int c, t_var *v)
{
	t_stak		*tmp;

	tmp = NULL;
	if (c == 1)
	{
		ft_putstr_fd("pb\n", v->fd);
		p_stk(a, b, tmp);
		free(tmp);
	}
	else if (c == 2)
	{
		ft_putstr_fd("ra\n", v->fd);
		r_stk(a);
		free(tmp);
	}
	else if (c == 3 && list_size(*a) > 1)
	{
		ft_putstr_fd("rra\n", v->fd);
		rr_stk(a, tmp);
	}
	else
		next_case(a, b, c, v);
}
