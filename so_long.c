/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:21:57 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/23 13:08:13 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen_2d(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
int ad_img(t_ptr *data)
{
	draw_map_P(data);
	draw_map_0(data);
	draw_map_1(data);
	draw_map_C(data);
	draw_map_E(data);
	return (0);
}
void parcing(char **argv, t_ptr *data)
{
	data->tab = ft_read(argv);
	data->height = ft_strlen_2d(data->tab);
	ft_check_ber(argv[1], data);
	ft_count(data);
	ft_check_one(data);
	ft_check_cote(data);
	ft_check(data);
	check_flood_fill(data);
}

int main(int argc , char **argv)
{
	if (argc == 2)
	{	
		t_ptr data;
		data.C = 0;
		data.moves = 0;
		parcing(argv, &data);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx,ft_strlen(data.tab[0]) * 40, ft_strlen_2d(data.tab) * 40,"so_long");
		mlx_loop_hook(data.mlx, &ad_img, &data);
		mlx_hook(data.win,2,0,&hook,&data);
		mlx_loop(data.mlx);
	}
	return (0);
}