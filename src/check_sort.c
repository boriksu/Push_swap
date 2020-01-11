/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:58:46 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/03 17:36:26 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_sort(t_tack *all)
{
	int i;

	if (all->size_b != 0)
	{
		all->bu.c == 1 ? ft_printf(ANSI_COLOR_RED "KO" ANSI_COLOR_RESET "\n") :
			write(1, "KO\n", 3);
		return ;
	}
	i = 0;
	while (i < all->argc - 1)
		if (all->a[i] < all->a[i + 1])
			i++;
		else
		{
			all->bu.c == 1 ? ft_printf(ANSI_COLOR_RED "KO" ANSI_COLOR_RESET
					"\n") : write(1, "KO\n", 3);
			return ;
		}
	all->bu.c == 1 ? ft_printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n") :
		write(1, "OK\n", 3);
}

int		ft_check_sort_spec(t_tack *all)
{
	int i;

	i = 0;
	if (all->size_b != 0)
		return (0);
	while (i < all->argc - 1)
		if (all->a[i] < all->a[i + 1])
			i++;
		else
			return (0);
	return (1);
}

void	ft_exit(t_tack *all, int a)
{
	a = 0;
	if (all->argc != -5)
	{
		ft_intdel(&all->a);
		ft_intdel(&all->b);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_do_struct(t_tack *all)
{
	if (all->argc == 0)
		exit(1);
	all->a = (int*)malloc(sizeof(int) * all->argc);
	all->b = (int*)malloc(sizeof(int) * all->argc);
	all->size_b = 0;
	all->size_a = all->argc;
	all->index_a = 0;
	all->index_b = all->argc;
}

void	ft_do_struct1(t_tack *all)
{
	all->argc = -5;
	all->bu.c = 0;
	all->bu.v = 0;
	all->bu.f = 0;
}
