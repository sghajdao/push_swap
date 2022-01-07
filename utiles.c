/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghajdao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:34:35 by sghajdao          #+#    #+#             */
/*   Updated: 2021/12/23 15:34:43 by sghajdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(float num)
{
	int	i;

	i = (int)num;
	if ((num - i) >= 0.5)
		return ((int) num + 1);
	else
		return ((int) num);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
	else
		return ;
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		size;

	size = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (!s2)
		return (0);
	i = 0;
	while (*((char *)s1 + i))
	{
		s2[i] = *((char *)s1 + i);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			if (s1[i] > s2[i])
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}

void	ft_free_arg(char **arg)
{
	if (*arg)
		free(*arg);
	*arg = NULL;
}
