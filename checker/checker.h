/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:38:49 by sghajdao          #+#    #+#             */
/*   Updated: 2022/01/03 11:39:56 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				*array;
	size_t			size;
}	t_stack;

typedef struct s_instruction
{
	char			*line;
	void			*next;
}	t_instruction;

typedef struct s_program
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_instruction	*instr;
}	t_program;

int		stack_contains(t_stack *stack, int num);
int		init_stacks(int argc, char **argv,
			t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	push_stack(t_stack *stack1, t_stack *stack2);
void	swap_stack(t_stack *stack);
void	free_instructions(t_instruction *instructions);
void	execute_instructions(t_instruction *instr, t_stack *stack_a,
			t_stack *stack_b);
int		add_instruction(t_instruction **intructions, char *line);
int		get_instruction(t_instruction **instructions);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *str, int *num);
void	write_n_char(int n, char c);
int		size_nbr(int n);
int		get_max_size_nbr_stack(t_stack *stack);
int		free_prg(t_program *prg);
int		compar(char *line);
int		check_err(t_stack *stack_a, t_stack *stack_b, int size);

#endif
