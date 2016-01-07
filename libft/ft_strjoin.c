/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:53:26 by amineau           #+#    #+#             */
/*   Updated: 2015/12/01 11:07:45 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!(dst = (char*)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	if (s1)
	{
		while (s1[++i])
			dst[i] = s1[i];
	}
	if (s2)
	{
		while (s2[++j])
			dst[i + j] = s2[j];
	}
	dst[i + j] = '\0';
	return (dst);
}
