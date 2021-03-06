/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:30:31 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/16 16:35:56 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*p;
	int		i;

	i = 0;
	p = begin_list;
	while (p != NULL)
	{
		p = p->next;
		i++;
	}
	return (i);
}
