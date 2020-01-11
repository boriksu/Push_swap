/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 15:13:06 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/26 19:37:55 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_tack *all, int a)
{
	if (all->size_b == 0)
		return ;
	all->a[all->index_a - 1] = all->b[all->index_b];
	all->index_a--;
	all->index_b++;
	all->size_a++;
	all->size_b--;
	if (a == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_tack *all, int a)
{
	if (all->size_a == 0)
		return ;
	all->b[all->index_b - 1] = all->a[all->index_a];
	all->index_a++;
	all->index_b--;
	all->size_b++;
	all->size_a--;
	if (a == 1)
		write(1, "pb\n", 3);
}
