/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:05:03 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/03 17:44:37 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_str_is_digit(char *str)
{
	int i;
	int flag;
	int space;

	i = 0;
	flag = 0;
	space = 1;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' && space++ > -1)
			i++;
		if (space == 0)
			return (0);
		if (str[i] == '\0')
			return (flag);
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			space = ft_str_dig_help(str, &i, &flag);
		else
			return (0);
	}
	return (flag);
}

int		ft_str_dig_help(char *str, int *i, int *flag)
{
	while (str[*i] >= '0' && str[*i] <= '9')
		*i = *i + 1;
	*flag = *flag + 1;
	return (0);
}

int		ft_check_dup(int *a, int n)
{
	int i;
	int j;

	j = 0;
	while (j < n)
	{
		i = 0;
		while (i < j)
			if (a[i] == a[j])
				return (0);
			else
				i++;
		j++;
	}
	return (1);
}

int		ft_how_many(int argc, char **argv, t_tack *all, int flag)
{
	int i;
	int num;
	int check;

	i = 0;
	num = 0;
	while (++i < argc)
	{
		if (flag == 1 && ft_check_bonus(&all->bu, argv[i]) == 1)
			continue ;
		if ((check = ft_str_is_digit(argv[i])) == 0)
			ft_exit(all, 0);
		num += check;
	}
	return (num);
}

int		ft_check_bonus(t_bonus *bonus, char *str)
{
	if (ft_strcmp(str, "-c") == 0)
		bonus->c = 1;
	else if (ft_strcmp(str, "-v") == 0)
	{
		if (bonus->f == 1)
			bonus->f = 0;
		bonus->v = 1;
	}
	else if (ft_strcmp(str, "-f") == 0)
	{
		if (bonus->v != 1)
			bonus->f = 1;
	}
	else
		return (0);
	return (1);
}
