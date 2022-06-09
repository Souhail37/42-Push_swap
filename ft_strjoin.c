/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:56 by eseiv             #+#    #+#             */
/*   Updated: 2022/04/27 16:04:56 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen1(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin1(char *buffers, char *buff, char c)
{
	int		i;
	int		j;
	char	*new;

	if (!buffers)
	{
		buffers = (char *)malloc(sizeof(char));
		buffers[0] = '\0';
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen1(buffers)
				+ ft_strlen1(buff) + 2));
	if (!new)
		return (0);
	i = -1;
	j = 0;
	while (buffers[++i])
		new[i] = buffers[i];
	new[i++] = c;
	while (buff[j])
		new[i++] = buff[j++];
	new[i] = '\0';
	free (buffers);
	return (new);
}

void	ft_joinargs(char **str, char **av)
{
	int	i;

	*str = NULL;
	i = 1;
	while (av[i])
	{
		*str = ft_strjoin1(*str, av[i], ' ');
		i++;
	}
}

void	ft_init(t_list *var)
{
	var->st_a_len = var->j;
	var->st_b_len = 0;
	ft_init_a(var->stack_a, var->spl);
	ft_init_b(var->stack_b, var->j);
}

void	ft_args(t_list *var, char **av)
{
	ft_joinargs(&var->str, av);
	var->spl = ft_split(var->str, ' ');
	while (var->spl[var->j])
		var->j++;
}
