/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:46:07 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/27 16:18:41 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../push_swap.h"
#include "../gnl/get_next_line.h"

void	ft_free(t_list *var)
{
	int	i;

	i = 0;
	while (var->spl[i])
		free(var->spl[i++]);
	free(var->spl);
	free(var->str);
	if (var->stack_a)
		free(var->stack_a);
	if (var->stack_b)
		free(var->stack_b);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	checker_instruct(t_list *var, char *instruct, int ac)
{
	if (ft_strcmp(instruct, "sa\n") == 0)
		swap1_a(*var);
	else if (ft_strcmp(instruct, "sb\n") == 0)
		swap1_b(*var);
	else if (ft_strcmp(instruct, "ss\n") == 0)
		ft_ss1(*var);
	else if (ft_strcmp(instruct, "ra\n") == 0)
		rot1_a(*var);
	else if (ft_strcmp(instruct, "rb\n") == 0)
		rot1_b(*var);
	else if (ft_strcmp(instruct, "rr\n") == 0)
		ft_rr1(*var);
	else if (ft_strcmp(instruct, "rra\n") == 0)
		rev_rot1_a(*var);
	else if (ft_strcmp(instruct, "rrb\n") == 0)
		rev_rot1_b(*var);
	else if (ft_strcmp(instruct, "rrr\n") == 0)
		ft_rrr1(*var);
	else if (ft_strcmp(instruct, "pa\n") == 0)
		push1_a(var, ac);
	else if (ft_strcmp(instruct, "pb\n") == 0)
		push1_b(var, ac);
	else
		return (0);
	return (1);
}

int	ft_checker(t_list *var, int fd, int ac)
{
	char	*instruct;

	instruct = get_next_line(fd);
	while (instruct)
	{
		if (!instruct)
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
		if (!checker_instruct(var, instruct, ac))
		{
			free(instruct);
			write(2, "ERROR\n", 6);
			return (0);
		}
		free(instruct);
		instruct = get_next_line(fd);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	var;

	if (ac > 1)
	{
		if (validarg(av + 1))
			return (1);
		ft_args(&var, av);
		if (!check_number(var.spl, var.i) || !check_double(var.spl, var.i)
			|| !check_int(var.j, var.spl))
			return (ft_free(&var), 1);
		var.stack_a = malloc(sizeof(t_stack) * var.j);
		var.stack_b = malloc(sizeof(t_stack) * var.j);
		if (!var.stack_a || !var.stack_b)
			return (0);
		ft_init(&var);
		if (!ft_checker(&var, 0, var.j))
			return (ft_free(&var), 1);
		if (ft_is_sorted(var.stack_a, var.j) && var.st_b_len == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		ft_free(&var);
	}
	return (0);
}
