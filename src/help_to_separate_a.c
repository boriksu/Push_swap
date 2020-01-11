/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_separate_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:40:31 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/14 16:03:43 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_trio(t_tack *all, int num_new_a, int *num)
{
	if (num_new_a == 3 && all->size_a != 3)
	{
		ft_swap_trio_a(all);
		*num = 0;
		return (-5);
	}
	return (num_new_a);
}

int		ft_find_three_in_a(t_tack *all, int *num, int count)
{
	*num = 0;
	if (all->size_a == 3)
	{
		ft_understand_for_a(all);
		return (-5);
	}
	return (count);
}

int		ft_go_to_b(t_tack *all, int *num)
{
	ft_pb(all, 1);
	*num = *num + 1;
	return (1);
}

int		ft_reverse_rotate(t_tack *all, t_eparate *a, int *num, int *count)
{
	int middle;
	int flag_inside;
	int ap;
	int start;

	start = a->k;
	flag_inside = 0;
	if (a->flag != 1)
		return (0);
	ap = all->index_a + all->size_a - a->k;
	if (start > 3)
		middle = ft_find_middle(all->a + ap, a->k);
	while (a->k > 0)
	{
		ft_rra(all, 1);
		if (start > 3 && all->a[all->index_a] < middle)
		{
			if (flag_inside == 0)
				*num = 0;
			flag_inside = ft_go_to_b(all, num);
			*count = *count - 1;
		}
		a->k--;
	}
	return (flag_inside);
}
