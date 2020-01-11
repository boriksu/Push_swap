/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:05:03 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/03 16:06:36 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		i;
	t_tack	all;
	int		j;

	if (argc == 1)
		exit(1);
	ft_do_struct1(&all);
	all.argc = ft_how_many(argc, argv, &all, 1);
	ft_do_struct(&all);
	i = 1;
	j = 0;
	while (i < argc)
	{
		ft_record_num(argv[i], &j, &all);
		i++;
	}
	if (ft_check_dup(all.a, all.argc) != 1)
		ft_exit(&all, 0);
	ft_read_fun(&all);
	if (all.bu.f == 1)
		ft_print(&all);
	ft_check_sort(&all);
	ft_intdel(&all.a);
	ft_intdel(&all.b);
	return (0);
}
