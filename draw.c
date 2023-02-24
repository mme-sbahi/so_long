/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:59 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/24 19:08:55 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map_1(t_ptr *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (data->tab[++i])
	{
		j = -1;
		x = 0;
		while (data->tab[i][++j])
		{
			if (data->tab[i][j] == '1')
			{
				data->img = mlx_xpm_file_to_image (data->mlx, "images/wall.xpm",
						&data->a, &data->b);
				if (!data->img)
					ft_error("ERROR : check mlx file", data->tab);
				mlx_put_image_to_window (data->mlx, data->win, data->img, x, y);
			}
			x += 40;
		}
		y += 40;
	}
}

void	draw_map_p(t_ptr *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (data->tab[++i])
	{
		j = -1;
		x = 0;
		while (data->tab[i][++j])
		{
			if (data->tab[i][j] == 'P')
			{
				data->img = mlx_xpm_file_to_image (data->mlx,
						"images/Player.xpm", &data->a, &data->b);
				if (!data->img)
					ft_error("ERROR : check mlx file", data->tab);
				mlx_put_image_to_window (data->mlx, data->win, data->img, x, y);
			}
			x += 40;
		}
		y += 40;
	}
}

void	draw_map_c(t_ptr *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (data->tab[++i])
	{
		j = -1;
		x = 0;
		while (data->tab[i][++j])
		{
			if (data->tab[i][j] == 'C')
			{
				data->img = mlx_xpm_file_to_image (data->mlx, "images/c.xpm",
						&data->a, &data->b);
				if (!data->img)
					ft_error("ERROR : check mlx file", data->tab);
				mlx_put_image_to_window (data->mlx, data->win, data->img, x, y);
			}
			x += 40;
		}
		y += 40;
	}
}

void	draw_map_e(t_ptr *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (data->tab[++i])
	{
		j = -1;
		x = 0;
		while (data->tab[i][++j])
		{
			if (data->tab[i][j] == 'E')
			{
				data->img = mlx_xpm_file_to_image (data->mlx, "images/exit.xpm",
						&data->a, &data->b);
				if (!data->img)
					ft_error("ERROR : check mlx file", data->tab);
				mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
			}
			x += 40;
		}
		y += 40;
	}
}

void	draw_map_0(t_ptr *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (data->tab[++i])
	{
		j = -1;
		x = 0;
		while (data->tab[i][++j])
		{
			if (data->tab[i][j] == '0')
			{
				data->img = mlx_xpm_file_to_image(data->mlx, "images/floor.xpm",
						&data->a, &data->b);
				if (!data->img)
					ft_error("ERROR : check mlx file", data->tab);
				mlx_put_image_to_window(data->mlx, data->win, data->img, x, y);
			}
			x += 40;
		}
		y += 40;
	}
}
