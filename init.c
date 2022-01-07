/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:14:51 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:14:54 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	*ft_init_var(t_var *v)
{
	v = (t_var *)malloc(sizeof(t_var));
	if (v == NULL)
		exit(1);
	v->a = NULL;
	v->b = NULL;
	v->len = 0;
	v->split = NULL;
	return (v);
}
