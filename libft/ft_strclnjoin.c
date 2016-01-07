/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclnjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:36:01 by amineau           #+#    #+#             */
/*   Updated: 2016/01/05 16:38:41 by amineau          ###   ########.fr       */
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
	free((char*)s1);
	if (s2)
	{
		while (s2[++j])
			dst[i + j] = s2[j];
	}
	free((char*)s2);
	dst[i + j] = '\0';
	return (dst);
}
