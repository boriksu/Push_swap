/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:00:41 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/03 16:46:58 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_rule(char *buf)
{
	if (buf[0] == 's')
	{
		if (buf[1] == 'a' && buf[2] == '\0')
			return (1);
		else if (buf[1] == 'b' && buf[2] == '\0')
			return (2);
		else if (buf[1] == 's' && buf[2] == '\0')
			return (3);
	}
	else if (buf[0] == 'p' && buf[1] == 'a' && buf[2] == '\0')
		return (4);
	else if (buf[0] == 'p' && buf[1] == 'b' && buf[2] == '\0')
		return (5);
	else if (buf[0] == 'r')
	{
		if (buf[1] == 'a' && buf[2] == '\0')
			return (6);
		else if (buf[1] == 'b' && buf[2] == '\0')
			return (7);
		else if (buf[1] == 'r')
			return (ft_check_letter(buf[2], buf[3]));
	}
	return (0);
}

int		ft_check_letter(char c, char k)
{
	if (c == '\0')
		return (8);
	else if (c == 'a' && k == '\0')
		return (9);
	else if (c == 'b' && k == '\0')
		return (10);
	else if (c == 'r' && k == '\0')
		return (11);
	else
		return (0);
}

void	ft_record_func(void (*fun[12])(t_tack*, int), int *i)
{
	*i = 0;
	fun[0] = &ft_exit;
	fun[1] = &ft_sa;
	fun[2] = &ft_sb;
	fun[3] = &ft_ss;
	fun[4] = &ft_pa;
	fun[5] = &ft_pb;
	fun[6] = &ft_ra;
	fun[7] = &ft_rb;
	fun[8] = &ft_rr;
	fun[9] = &ft_rra;
	fun[10] = &ft_rrb;
	fun[11] = &ft_rrr;
}

void	ft_read_fun(t_tack *all)
{
	char	*buf;
	char	c[1];
	int		i;
	void	(*fun[12])(t_tack*, int);

	ft_record_func(fun, &i);
	buf = ft_memalloc(4);
	while (read(0, c, 1) > 0)
		if (c[0] == '\n')
		{
			i = ft_check_rule(buf);
			ft_del_n_apply(all, &buf, fun[i]);
			buf = ft_memalloc(4);
			i = 0;
		}
		else
		{
			if (i == 3)
				ft_del_n_apply(all, &buf, fun[0]);
			buf[i] = c[0];
			i++;
		}
	if (buf[0] != '\0')
		ft_del_n_apply(all, &buf, fun[0]);
	ft_strdel(&buf);
}

void	ft_del_n_apply(t_tack *all, char **buf, void (*fun)(t_tack*, int))
{
	ft_strdel(buf);
	fun(all, 0);
	if (all->bu.v == 1)
		ft_print(all);
}
