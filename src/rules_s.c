/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:17:58 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/27 15:58:23 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_tack *all, int a)
{
	int c;

	if (all->size_a < 2)
		return ;
	c = all->a[all->index_a];
	all->a[all->index_a] = all->a[all->index_a + 1];
	all->a[all->index_a + 1] = c;
	if (a == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_tack *all, int a)
{
	int c;

	if (all->size_b < 2)
		return ;
	c = all->b[all->index_b];
	all->b[all->index_b] = all->b[all->index_b + 1];
	all->b[all->index_b + 1] = c;
	if (a == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_tack *all, int a)
{
	ft_sa(all, 0);
	ft_sb(all, 0);
	if (a == 1)
		write(1, "ss\n", 3);
}
