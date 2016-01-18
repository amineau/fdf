/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:50:31 by amineau           #+#    #+#             */
/*   Updated: 2016/01/14 14:41:43 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coor_clear(t_coor **cr)
{
	t_coor	*tmp;
	t_coor	*tmp2;

	if (*cr)
	{
		tmp = *cr;
		while (tmp)
		{
			tmp2 = tmp;
			tmp = tmp->next;
			free(tmp2->tab);
			free(tmp2);
		}
	}
}

void	split_clear(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int		test_map(t_coor **cr)
{
	t_coor	*tmp;

	tmp = *cr;
	while (tmp->next)
	{
		if (tmp->lenght != tmp->next->lenght)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void	recup_error(int i, t_coor **cr)
{

	if (i > 2)
		coor_clear(cr);
	if (i > 0)
		free(cr);
	ft_putstr("error : ");
	if (i == 0 || i == 3)
		ft_putendl("pointer not allocated with malloc");
	if (i == 1)
		ft_putendl("open file failed");
	if (i == 2)
		ft_putendl("map error");
	if (i == 4)
		ft_putendl("close file failed");
	if (i == 5)
		ft_putendl("map invalid");
	exit(0);
}