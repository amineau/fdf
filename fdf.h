/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:58:35 by amineau           #+#    #+#             */
/*   Updated: 2016/01/10 11:27:56 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_env
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	void	*mlx;
	void	*win;
}				t_env;

#endif
