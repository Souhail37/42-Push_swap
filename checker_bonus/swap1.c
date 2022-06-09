/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 02:53:04 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/26 02:54:14 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack *temp1, t_stack *temp2)
{
	t_stack	temp;

	temp = *temp1;
	*temp1 = *temp2;
	*temp2 = temp;
}

void	swap1_a(t_list var)
{
	ft_swap(&var.stack_a[0], &var.stack_a[1]);
}

void	swap1_b(t_list var)
{
	ft_swap(&var.stack_b[0], &var.stack_b[1]);
}

void	ft_ss1(t_list var)
{
	ft_swap(&var.stack_a[0], &var.stack_a[1]);
	ft_swap(&var.stack_b[0], &var.stack_b[1]);
}
