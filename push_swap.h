/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:14:57 by dholiday          #+#    #+#             */
/*   Updated: 2019/08/14 15:58:27 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_bonus
{
	int			c;
	int			v;
	int			f;
}				t_bonus;

typedef struct	s_tack
{
	int			argc;
	int			*a;
	int			*b;
	int			size_a;
	int			size_b;
	int			index_a;
	int			index_b;
	t_bonus		bu;
}				t_tack;

typedef struct	s_eparate
{
	int			k;
	int			j;
	int			middle;
	int			flag;
	int			kvartil;
}				t_eparate;

void			ft_sa(t_tack *all, int a);
void			ft_sb(t_tack *all, int a);
void			ft_ss(t_tack *all, int a);

void			ft_pa(t_tack *all, int a);
void			ft_pb(t_tack *all, int a);

void			ft_ra(t_tack *all, int a);
void			ft_rb(t_tack *all, int a);
void			ft_rr(t_tack *all, int a);

void			ft_rra(t_tack *all, int a);
void			ft_rrb(t_tack *all, int a);
void			ft_rrr(t_tack *all, int a);

int				ft_str_is_digit(char *str);
int				ft_str_dig_help(char *str, int *i, int *flag);
int				ft_check_dup(int *a, int n);
void			ft_exit(t_tack *all, int a);
int				ft_atoi2(const char *str, t_tack *all);
int				ft_how_many(int argc, char **argv, t_tack *all, int flag);
void			ft_record_num(char *argv, int *j, t_tack *all);

int				ft_check_rule(char *buf);
int				ft_check_letter(char c, char k);
void			ft_record_func(void (*fun[12])(t_tack*, int), int *i);
void			ft_read_fun(t_tack *all);
void			ft_del_n_apply(t_tack *all, char **buf,
		void (*fun)(t_tack*, int));

void			ft_check_sort(t_tack *all);
void			ft_intdel(int **ap);
void			ft_do_struct(t_tack *all);
void			ft_do_struct1(t_tack *all);

int				ft_find_middle(int *a, int num_new);
int				ft_find_kra(int *a, int num_new, int middle);
int				ft_check_sort_spec(t_tack *all);
void			ft_sort_q(t_tack *all);
int				ft_separate_new_b(t_tack *all, int num_new_b);
void			ft_separate_new_a(t_tack *all, int num_new_a,
		int *i, int *num_new_b);

int				ft_reverse_rotate(t_tack *all, t_eparate *a,
		int *num, int *count);
void			ft_reverse_rotate_b(t_tack *all, int k, int flag);
int				ft_check_num(int num_new, int count);
void			ft_check_swap_back(t_tack *all, int *num_new_b, int *i);
void			ft_write_struct(t_eparate *n, t_tack *all, int c, int num);
int				ft_find_trio(t_tack *all, int num_new_a, int *num);
int				ft_find_three_in_a(t_tack *all, int *num, int count);
int				ft_go_to_b(t_tack *all, int *num);

void			ft_understand_for_a(t_tack *all);
void			ft_find_min_a(t_tack *all, int *min, int *max);
void			ft_find_min_b(t_tack *all, int *min, int *max);
void			ft_understand_for_b(t_tack *all);
void			ft_swap_trio_a(t_tack *all);
void			ft_use_fun(t_tack *all, char *str);

int				ft_check_bonus(t_bonus *bonus, char *str);
void			ft_print_b(t_tack *all);
void			ft_print(t_tack *all);

#endif
