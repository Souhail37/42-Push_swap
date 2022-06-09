/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:26:59 by sismaili          #+#    #+#             */
/*   Updated: 2022/04/27 16:05:19 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct s_stack
{
	int		pos;
	int		value;
	int		size;
}	t_stack;

typedef struct list
{
	char	*str;
	char	**spl;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		st_a_len;
	int		st_b_len;
	int		i;
	int		j;
}	t_list;

int		ft_atoi(const char *str);
long	ft_atol(char *str);
char	**ft_split(char const *s, char c);
void	ft_joinargs(char **str, char **av);
void	ft_free(t_list *var);
size_t	ft_strlen(char *str);
void	ft_init_a(t_stack *new, char **av);
void	ft_init_b(t_stack *new, int ac);
void	ft_pushswap(t_list var, int ac);
void	ft_done(t_list var, char **spl, int j);
void	ft_pushswap(t_list var, int ac);
void	ft_init(t_list *var);
void	ft_init_a(t_stack *new, char **av);
void	ft_init_b(t_stack *new, int ac);
int		validarg(char **args);
void	ft_args(t_list *var, char **av);
void	swap_a(t_list var);
void	swap_b(t_list var);
void	ft_ss(t_list var);
void	rot_a(t_list var);
void	rot_b(t_list var);
void	ft_rr(t_list var);
void	rev_rot_a(t_list var);
void	rev_rot_b(t_list var);
void	ft_rrr(t_list var);
void	sort_3_a(t_list var);
void	sort_less_10(t_list *var, int ac);
void	push_b(t_list *var, int ac);
void	push_a(t_list *var, int ac);
int		ft_is_sorted(t_stack *var, int ac);
int		ft_isthere(t_list *var, int size);
void	simple_sort(t_stack *array, int size);
void	copy_element(t_stack *temp, t_stack *stack, int len);
void	take_index(t_stack *temp, t_stack *stack, int len);
void	to_top_a(t_list *var, int size, int save, int ac);
void	to_top_b(t_list *var, int max, int i, int ac);
void	just_sort(t_list *var, int number, int ac);
int		ft_max(t_stack *var, int len, int *pos);
int		ft_min(t_stack *var, int len);
int		check_number(char **av, int i);
int		check_double(char **av, int i);
int		check_int(int ac, char **av);
int		ft_checker(t_list *var, int fd, int ac);

#endif