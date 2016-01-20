/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amineau <amineau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:58:35 by amineau           #+#    #+#             */
/*   Updated: 2016/01/20 17:09:18 by amineau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_coor
{
	int				*tab;
	int				len;
	struct s_coor	*next;
}				t_coor;

typedef struct	s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct	s_env
{
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	double	max;
	int		ctr_x;
	int		ctr_y;
	int		pos_x;
	int		pos_y;
	int		color;
	double	al;
	double	om;
	double	cf;
	double	k;
	double	h;
	size_t	size_x;
	size_t	size_y;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_pix;
	int		size_line;
	int		end;
	t_coor	**cr;
}				t_env;

typedef struct	s_seg
{
	int		dx;
	int		dy;
	int		dp;
	int		deltae;
	int		deltane;
	int		x;
	int		y;
}				t_seg;

void			display_segment(t_seg *s, t_env *e, int a, int b);
void			display_map(t_env *e);
void			segment(t_env *e);
void			split_clear(char **split);
void			coor_clear(t_coor **cr);
void			recup_error(int i, t_coor **cr);
int				len_y(t_coor **cr);
int				test_map(t_coor **cr);
int				motion_notify(int x, int y, t_env *e);
int				key_press(int keycode, t_env *e);
int				mouse_press(int button, int x, int y, t_env *e);
int				expose_hook(t_env *e);
double			find_max(t_coor **cr);
t_coor			**recup(char *str);

#endif
