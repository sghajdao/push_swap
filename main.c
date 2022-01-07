/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:18:35 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:18:43 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

char	**fill_args(t_var *v, int ac, char **av)
{
	v->fd = 1;
	if (ac == 2)
		v->split = ft_split(av[1], ' ');
	else
		v->split = &av[1];
	return (v->split);
}

void	push_swap(t_var *v, int ac, char **av)
{
	t_stak	*stk;

	stk = NULL;
	v->split = fill_args(v, ac, av);
	check_dup(v->split);
	check_numbers(v->split);
	v->a = fill_list(v, v->split, stk);
	if (check_sort(&v->a, list_size(v->a)) == 1)
		ft_exit_ps("Error\n", 0);
	v->len = list_size(v->a);
	free_stk(&stk);
	if (v->len <= 10)
		sort_short(&(v->a), &(v->b), v->len, v);
	else
		sort_bigger(&(v->a), &(v->b), v->len, v);
	if (ac == 2 || (ac == 3 && v->fd != 1))
		ft_free_array(v->split);
	close(v->fd);
}

void	ft_exit_ps(char *arg, int err)
{
	if (err != 0)
		ft_putstr_fd(arg, 2);
	exit(err);
}

int	main(int ac, char **av)
{
	t_var	*v;

	v = NULL;
	if (ac < 2)
		return (0);
	else
	{
		v = ft_init_var(v);
		push_swap(v, ac, av);
		free(v);
		v = NULL;
	}
}
