/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:41:46 by sghajdao          #+#    #+#             */
/*   Updated: 2022/01/03 11:41:47 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	compar(char *line)
{
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")
		&& ft_strcmp(line, "ss") && ft_strcmp(line, "pa")
		&& ft_strcmp(line, "pb")
		&& ft_strcmp(line, "ra") && ft_strcmp(line, "rb")
		&& ft_strcmp(line, "rr")
		&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb")
		&& ft_strcmp(line, "rrr"))
		return (1);
	else
		return (0);
}

int	check_err(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->array = malloc(sizeof(int) * size);
	if (!stack_a->array)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_b->array = malloc(sizeof(int) * size);
	if (!stack_b->array)
	{
		free(stack_a->array);
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	free_prg(t_program *prg)
{
	free_instructions(prg->instr);
	free(prg->stack_a.array);
	free(prg->stack_b.array);
	return (0);
}
