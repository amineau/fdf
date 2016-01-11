/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:58:35 by amineau           #+#    #+#             */
/*   Updated: 2016/01/11 11:52:34 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_coor
{
	int				*tab;
	int				start;
	int				lenght;
	struct s_coor	*next;
}				t_coor;

typedef struct	s_env
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		alpha;
	int		omega;
	int		k;
	size_t	size_x;
	size_t	size_y;
	void	*mlx;
	void	*win;
	t_coor	**cr;
}				t_env;

typedef struct	s_seg
{
	int		dx;
	int		dy;
	int		dp;
	int		deltaE;
	int		deltaNE;
	int		x;
	int		y;
}				t_seg;

void			display_segment(t_seg *s, t_env *e, int a, int b);
void			display_map(t_env *e);
void			segment(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				expose_hook(t_env *e);
t_coor			**recup(char *str);

#endif
