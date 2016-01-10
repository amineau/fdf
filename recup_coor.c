/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_coor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:17:40 by amineau           #+#    #+#             */
/*   Updated: 2016/01/10 16:11:26 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**recup(char *str)
{
	int		fd;
	int		x;
	char	**tab;

	tab = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (tab);
	x = 0;
	while (get_next_line(fd, &tab[x++]) == 1)
		;
	tab[x] = NULL;
	return (tab);
}
