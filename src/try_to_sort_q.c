/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_sort_q.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:40:31 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/14 15:50:11 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_swap_back(t_tack *all, int *num_new_b, int *i)
{
	if (all->a[all->index_a] > all->a[all->index_a + 1])
		ft_sa(all, 1);
	if (num_new_b[*i - 1] == 1)
	{
		ft_pa(all, 1);
		*i = *i - 2;
	}
	else if (num_new_b[*i - 1] == 2)
	{
		if (all->b[all->index_b] < all->b[all->index_b + 1])
			ft_sb(all, 1);
		ft_pa(all, 1);
		ft_pa(all, 1);
		*i = *i - 2;
	}
	else
		*i = *i - 1;
}

void	ft_sort_q(t_tack *all)
{
	int i;
	int num_new_b[50];
	int num_new_a;

	i = 0;
	num_new_a = all->size_a;
	while (ft_check_sort_spec(all) != 1)
	{
		ft_separate_new_a(all, num_new_a, &i, num_new_b);
		ft_check_swap_back(all, num_new_b, &i);
		if (all->size_b != 0)
			num_new_a = ft_separate_new_b(all, num_new_b[i]);
		if (i >= 0)
			num_new_b[i] = num_new_b[i] - num_new_a;
		i++;
	}
}

int		ft_separate_new_b(t_tack *all, int num_new_b)
{
	int			num_new_a;
	t_eparate	b;

	num_new_a = 0;
	ft_write_struct(&b, all, 2, num_new_b);
	while (++b.j < num_new_b)
	{
		if (all->b[all->index_b] < b.middle)
		{
			ft_rb(all, 1);
			b.k++;
		}
		else
		{
			ft_pa(all, 1);
			num_new_a++;
		}
		if (ft_check_num(num_new_b, num_new_a) == 0)
			break ;
	}
	ft_reverse_rotate_b(all, b.k, b.flag);
	return (num_new_a);
}

void	ft_separate_new_a(t_tack *all, int num_new_a, int *i, int *num_new_b)
{
	int			count;
	t_eparate	a;

	count = ft_find_trio(all, num_new_a, &num_new_b[*i]);
	while (count > 2)
	{
		ft_write_struct(&a, all, 1, count);
		if ((num_new_a = ft_find_three_in_a(all, &num_new_b[*i], count)) == -5)
			return ;
		if (count == 3 && ft_find_trio(all, count, &num_new_b[*i]) == -5)
			return ;
		while (++a.j < num_new_a)
		{
			if (all->a[all->index_a] >= a.middle)
			{
				(num_new_b[*i] == all->size_b && all->b[all->index_b]
				< a.kvartil) ? ft_rr(all, 1) : ft_ra(all, 1);
				a.k++;
			}
			else
				count -= ft_go_to_b(all, &num_new_b[*i]);
		}
		*i = *i + 1;
		*i = *i + ft_reverse_rotate(all, &a, &num_new_b[*i], &count);
	}
}
