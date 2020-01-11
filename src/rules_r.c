/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:48:07 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/05 20:12:32 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_tack *all, int a)
{
	int c;
	int i;

	i = all->index_a;
	if (all->size_a > 1)
	{
		c = all->a[i];
		while (i < all->argc - 1)
		{
			all->a[i] = all->a[i + 1];
			i++;
		}
		all->a[i] = c;
	}
	if (a == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_tack *all, int a)
{
	int c;
	int i;

	i = all->index_b;
	if (all->size_b > 1)
	{
		c = all->b[i];
		while (i < all->argc - 1)
		{
			all->b[i] = all->b[i + 1];
			i++;
		}
		all->b[i] = c;
	}
	if (a == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_tack *all, int a)
{
	ft_ra(all, 0);
	ft_rb(all, 0);
	if (a == 1)
		write(1, "rr\n", 3);
}
