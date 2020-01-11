/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_q.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 19:24:52 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/30 18:56:01 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_understand_for_a(t_tack *all)
{
	int min;
	int max;

	ft_find_min_a(all, &min, &max);
	if (max == min + 2)
		return ;
	else if (min + 1 == max && min == all->index_a)
	{
		ft_sa(all, 1);
		ft_ra(all, 1);
	}
	else if (max + 1 == min && max == all->index_a)
		ft_ra(all, 1);
	else if (max + 1 == min)
		ft_rra(all, 1);
	else if (min + 1 == max)
		ft_sa(all, 1);
	else if (max + 2 == min)
	{
		ft_sa(all, 1);
		ft_rra(all, 1);
	}
}

void	ft_find_min_a(t_tack *all, int *min, int *max)
{
	int i;
	int j;

	*min = all->index_a;
	*max = all->index_a;
	i = all->index_a;
	j = 0;
	while (j < all->size_a)
	{
		if (all->a[i] < all->a[*min])
			*min = i;
		else if (all->a[i] > all->a[*max])
			*max = i;
		i++;
		j++;
	}
}

void	ft_swap_trio_a(t_tack *all)
{
	int a;
	int b;
	int c;

	a = all->a[all->index_a];
	b = all->a[all->index_a + 1];
	c = all->a[all->index_a + 2];
	if (a < b && b < c)
		return ;
	else if (a < b && b > c && a < c)
		ft_use_fun(all, "619");
	else if (a > b && a < c && b < c)
		ft_sa(all, 1);
	else if (a < b && a > c && b > c)
		ft_use_fun(all, "6191");
	else if (a > b && b > c)
		ft_use_fun(all, "16191");
	else if (a > b && b < c && a > c)
		ft_use_fun(all, "1619");
}

void	ft_use_fun(t_tack *all, char *str)
{
	int		i;
	void	(*fun[12])(t_tack*, int);
	int		k;

	ft_record_func(fun, &i);
	while (str[i] != '\0')
	{
		k = 0 + str[i] - '0';
		fun[k](all, 1);
		i++;
	}
}
