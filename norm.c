/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:18:55 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:18:59 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_a(t_stak **a, t_stak **b, t_var *v, int pvt)
{
	int	idx;
	int	num;

	idx = get_idx((*a), pvt, 1);
	num = (list_size((*a)) / 2);
	if (idx < num)
		pick_case(a, b, ra(), v);
	else
		pick_case(a, b, rra(), v);
}

void	normalize_b(t_stak **a, t_stak **b, t_var *v, int pvt)
{
	int	idx;
	int	num;

	idx = get_idx((*b), pvt, 2);
	num = ft_abs((list_size((*b)) / 2));
	if (idx < num && *b)
		pick_case(a, b, rb(), v);
	else if (*b)
		pick_case(a, b, rrb(), v);
}
