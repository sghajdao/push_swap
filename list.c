/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:17:30 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:17:35 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stak	*fill_list(t_var *v, char **split, t_stak *tmp)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		tmp = malloc(sizeof(t_stak));
		if (!tmp)
			return (NULL);
		tmp->num = ft_atoi(split[i]);
		if (tmp->num > 2147483647 || tmp->num < -2147483648)
			ft_exit_ps("ERROR - int overflow.\n", 1);
		tmp->nxt = NULL;
		tmp->prv = NULL;
		add_back(&v->a, tmp);
		tmp = NULL;
	}
	return (v->a);
}
