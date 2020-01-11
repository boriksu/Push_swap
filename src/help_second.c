/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:40:31 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/05 19:38:49 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_b(t_tack *all, int k, int flag)
{
	if (flag == 1)
		while (k > 0)
		{
			ft_rrb(all, 1);
			k--;
		}
}

int		ft_check_num(int num_new, int count)
{
	if ((num_new % 2) == 1 && count == num_new / 2 + 1)
		return (0);
	if ((num_new % 2) == 0 && count == num_new / 2)
		return (0);
	return (1);
}

int		ft_find_middle(int *a, int num_new)
{
	int i;
	int j;
	int big;
	int little;

	i = 0;
	while (i < num_new)
	{
		j = 0;
		big = 0;
		little = 0;
		while (j < num_new)
		{
			(a[i] <= a[j]) ? big++ : little++;
			j++;
		}
		if (big == little || big == little + 1)
			return (a[i]);
		i++;
	}
	return (0);
}

void	ft_write_struct(t_eparate *n, t_tack *all, int c, int num)
{
	n->k = 0;
	n->j = -1;
	if (c == 1)
	{
		n->flag = num != all->size_a ? 1 : 0;
		n->middle = ft_find_middle(&all->a[all->index_a], num);
		n->kvartil = ft_find_kra(&all->a[all->index_a], num, n->middle);
	}
	else
	{
		n->flag = num != all->size_b ? 1 : 0;
		n->middle = ft_find_middle(&all->b[all->index_b], num);
	}
}

int		ft_find_kra(int *a, int num_new, int middle)
{
	int i;
	int j;
	int big;
	int little;

	i = 0;
	while (i < num_new)
	{
		if (a[i] < middle)
		{
			j = 0;
			big = 0;
			little = 0;
			while (j < num_new)
			{
				if (a[j] < middle)
					a[i] <= a[j] ? big++ : little++;
				j++;
			}
			if (big == little || big == little + 1)
				return (a[i]);
		}
		i++;
	}
	return (0);
}
