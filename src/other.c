/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:10:09 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/03 17:00:50 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi2(const char *str, t_tack *all)
{
	int					i;
	int					c;
	unsigned long int	b;
	int					k;

	b = 0;
	k = 1;
	i = 0;
	if (str[i] == '-')
	{
		i++;
		k = -1;
	}
	else if (str[i] == '+')
		i++;
	while ((c = str[i++]) > 47 && c < 58)
	{
		b = b * 10 + (c + 2) % 10;
		if (b > 2147483647 && k == 1)
			ft_exit(all, 0);
		else if (b > 2147483648 && k == -1)
			ft_exit(all, 0);
	}
	return (b * k);
}

void	ft_record_num(char *argv, int *j, t_tack *all)
{
	int i;

	i = 0;
	if (ft_check_bonus(&all->bu, argv) == 1)
		return ;
	while (argv[i] != '\0')
	{
		while (argv[i] == ' ')
			i++;
		if (argv[i] != '\0')
		{
			all->a[*j] = ft_atoi2(argv + i, all);
			*j = *j + 1;
		}
		while (argv[i] != ' ' && argv[i] != '\0')
			i++;
	}
}

void	ft_intdel(int **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_print(t_tack *all)
{
	int i;

	i = all->index_a;
	all->bu.c == 1 ? ft_printf(ANSI_COLOR_RESET "\n" ANSI_COLOR_YELLOW
			"a = "ANSI_COLOR_RESET) : ft_printf("\na = ");
	while (i < all->argc)
	{
		if (all->bu.c == 1 && i > all->index_a && all->a[i - 1] > all->a[i])
			ft_printf(ANSI_COLOR_RED "%d "ANSI_COLOR_RESET, all->a[i]);
		else if (all->bu.c == 1 && i != all->argc - 1 &&
				all->a[i] > all->a[i + 1])
			ft_printf(ANSI_COLOR_RED "%d "ANSI_COLOR_RESET, all->a[i]);
		else if (all->bu.c == 1)
			ft_printf(ANSI_COLOR_GREEN "%d "ANSI_COLOR_RESET, all->a[i]);
		else
			ft_printf("%d ", all->a[i]);
		i++;
	}
	ft_print_b(all);
}

void	ft_print_b(t_tack *all)
{
	int i;

	all->bu.c == 1 ? ft_printf(ANSI_COLOR_RESET "\n" ANSI_COLOR_YELLOW
			"b = "ANSI_COLOR_RESET) : ft_printf("\nb = ");
	i = all->index_b;
	while (i < all->argc)
	{
		if (all->bu.c == 1 && i > all->index_b && all->b[i - 1] > all->b[i])
			ft_printf(ANSI_COLOR_RED "%d "ANSI_COLOR_RESET, all->b[i]);
		else if (all->bu.c == 1 && i != all->argc - 1 &&
				all->b[i] > all->b[i + 1])
			ft_printf(ANSI_COLOR_RED "%d "ANSI_COLOR_RESET, all->b[i]);
		else if (all->bu.c == 1)
			ft_printf(ANSI_COLOR_GREEN "%d "ANSI_COLOR_RESET, all->b[i]);
		else
			ft_printf("%d ", all->b[i]);
		i++;
	}
	ft_printf("\n");
}
