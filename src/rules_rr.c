/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:57:56 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/05 20:13:05 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_tack *all, int a)
{
	int i;
	int c;

	i = all->argc - 1;
	if (all->size_a > 1)
	{
		c = all->a[i];
		while (i > all->index_a)
		{
			all->a[i] = all->a[i - 1];
			i--;
		}
		all->a[i] = c;
	}
	if (a == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_tack *all, int a)
{
	int i;
	int c;

	i = all->argc - 1;
	if (all->size_b > 1)
	{
		c = all->b[i];
		while (i > all->index_b)
		{
			all->b[i] = all->b[i - 1];
			i--;
		}
		all->b[i] = c;
	}
	if (a == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_tack *all, int a)
{
	ft_rra(all, 0);
	ft_rrb(all, 0);
	if (a == 1)
		write(1, "rrr\n", 4);
}
