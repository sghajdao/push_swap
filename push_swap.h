/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:10:16 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:32:04 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stak
{
	int				num;
	struct s_stak	*nxt;
	struct s_stak	*prv;
}	t_stak;

typedef struct s_var
{
	char	**split;
	int		len;
	int		fd;
	t_stak	*a;
	t_stak	*b;
}	t_var;

void		push_swap(t_var *v, int ac, char **av);
char		**fill_args(t_var *v, int ac, char **av);
void		rr_stk(t_stak **top, t_stak *tmp);
void		p_stk(t_stak **a, t_stak **b, t_stak *tmp);
void		r_stk(t_stak **top);
void		s_stk(t_stak **top);
int			check_sort(t_stak **a, int len);
void		check_dup(char **av);
int			check_numbers(char **av);
int			check_pivot(t_stak *a, int pvt, int flag);
void		pick_case(t_stak **a, t_stak **b, int c, t_var *v);
void		sort_short(t_stak **a, t_stak **b, int len, t_var *v);
void		sort_bigger(t_stak **a, t_stak **b, int len, t_var *v);
void		normalize_a(t_stak **a, t_stak **b, t_var *v, int pvt);
void		normalize_b(t_stak **a, t_stak **b, t_var *v, int pvt);
void		ft_exit_ps(char *arg, int err);
t_var		*ft_init_var(t_var *v);
t_stak		*fill_list(t_var *v, char **split, t_stak *tmp);
t_stak		*ft_lst_dup(t_stak *stk);
t_stak		*ft_lstsort(t_stak *stk);
int			list_size(t_stak *a);
void		add_back(t_stak **top, t_stak *new);
void		add_back_r(t_stak **top);
void		add_front(t_stak **top, t_stak *new);
void		free_stk(t_stak **stk);
t_stak		*ft_lst_bottom(t_stak *a);
int			ft_lstnbr(t_stak **stk, int idx);
int			get_min(t_stak *stk);
int			get_max(t_stak *stk);
int			get_idx(t_stak *stk, int num, int flag);
int			get_pivot(t_stak *stk);
int			ft_abs(float num);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strdup(const char *s1);
int			ft_strcmp(char *s1, char *s2);
void		ft_free_arg(char **arg);
size_t		ft_strlen(const char *s);
int			ft_isalpha(int c);
void		ft_bzero(void *s, size_t n);
char		**ft_split(char const *s, char c);
void		ft_free_array(char **array);
long long	ft_atoi(char *s);
int			pb(void);
int			ra(void);
int			rra(void);
int			pa(void);
int			rb(void);
int			rrb(void);
int			sb(void);
int			sa(void);

#endif
