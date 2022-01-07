/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:40:10 by sghajdao          #+#    #+#             */
/*   Updated: 2022/01/03 11:40:12 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_stack_ordered(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] >= stack->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	stack_contains(t_stack *stack, int num)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i++] == num)
			return (1);
	}
	return (0);
}

int	init_instructions(t_program *prg)
{
	int		ret;

	prg->instr = NULL;
	ret = get_instruction(&prg->instr);
	while (ret > 0)
		ret = get_instruction(&prg->instr);
	if (ret < 0)
	{
		free_instructions(prg->instr);
		free(prg->stack_a.array);
		free(prg->stack_b.array);
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	prg;

	if (--argc < 1 || argc == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (init_stacks(argc, &argv[1], &prg.stack_a, &prg.stack_b))
		return (1);
	if (init_instructions(&prg))
		return (1);
	execute_instructions(prg.instr, &prg.stack_a, &prg.stack_b);
	if (is_stack_ordered(&prg.stack_a) || prg.stack_b.size)
		write(2, "KO\n", 3);
	else
		write(2, "OK\n", 3);
	return (free_prg(&prg));
}
