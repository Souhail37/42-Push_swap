/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 02:51:00 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/26 23:44:08 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push1(t_list *var, char c, int ac)
{
	int	i;

	if (c == 'b')
	{
		i = ac - 1;
		while (i > 0)
		{
			var->stack_b[i] = var->stack_b[i - 1];
			i--;
		}
		var->stack_b[0] = var->stack_a[0];
		i = 0;
		while (i < var->st_a_len)
		{
			var->stack_a[i] = var->stack_a[i + 1];
			i++;
		}
		var->stack_a[i].value = 0;
		var->stack_a[i].pos = -1;
		var->st_a_len--;
		var->st_b_len++;
	}
}

void	ft_push(t_list *var, char c, int ac)
{
	int	i;

	ft_push1(var, c, ac);
	if (c == 'a')
	{
		i = var->st_a_len;
		while (i > 0)
		{
			var->stack_a[i] = var->stack_a[i - 1];
			i--;
		}
		var->stack_a[0] = var->stack_b[0];
		i = 0;
		while (i < var->st_b_len)
		{
			var->stack_b[i] = var->stack_b[i + 1];
			i++;
		}
		var->st_a_len++;
		var->st_b_len--;
	}
}

void	push1_b(t_list *var, int ac)
{
	if (var->st_a_len == 0)
		return ;
	ft_push(var, 'b', ac);
}

void	push1_a(t_list *var, int ac)
{
	if (var->st_b_len == 0)
		return ;
	ft_push(var, 'a', ac);
}
