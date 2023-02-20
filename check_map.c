/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:08:44 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/20 19:41:15 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
# include <mlx.h> 

void ft_check_ber(char *str)
{
	char *s1 = ft_substr(str,ft_strlen(str) - 4,4);
	if (ft_strcmp(s1,".ber") != 0)
	{
		ft_putstr("Error : no .ber in this file");
		exit(1);
	}
}
void	ft_check(t_ptr *data)
{
	int i;
	int j;
	int p;
	int e;
	int c;

	i = 0;
	p = 0;
	// j = 0;
	e = 0;
	c = 0;
	while (data->tab[i])
	{
		j = 0;
		while (data->tab[i][j])
		{
			if (data->tab[i][j] == 'P')
			{
				data->pos_player.x = i;
				data->pos_player.y = j;
				p++;
			}
			if(data->tab[i][j] == 'E')
				e++;
			if (data->tab[i][j] == 'C')
				data->C++;
			j++;
		}
		i++;
	}
	if (p != 1)
		ft_putstr("more than one player ");
	if (e != 1)
		ft_putstr("more than one exit");
	if (data->C < 1)
		ft_putstr("C");
}
void	ft_check_cote(t_ptr *data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (data->tab[j])
		j++;
	while (data->tab[i][0] && i < j - 1 )
	{
		if (data->tab[i][0] != '1')
			ft_putstr("map non valid \n");
		i++;
	}
	int s;
	s = ft_strlen(data->tab[0]) - 1;
	i = 0;
	while (data->tab[i][s] && i < j - 1 )
	{
		if (data->tab[i][s] != '1')
			ft_putstr("map non valid \n");
		i++;
	}
}
void	ft_check_one(t_ptr *data)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (data->tab[0][i])
	{
		if (data->tab[0][i] != '1')
		ft_putstr("map non valid\n");
		i++;
	}
	i = 0;
	while (data->tab[j])
	{
		j++;
	}
	while (data->tab[j - 1][i])
	{
		if (data->tab[j - 1][i] != '1')
			ft_putstr("map non valid \n");
		i++;
	}
} 
void	ft_count(t_ptr *data)
{
	int i;
	int j;
	int x;
	
	i = ft_strlen(data->tab[0]);
	j = 1;
	while (data->tab[j])
	{
		x = ft_strlen(data->tab[j]);
		if (x != i)
			ft_putstr("map non valid\n");
		j++;
	}
}
int ft_strlen_2d(char **str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
char **ft_read(char **argv)

{
	char *map;
	char **str;
	char	*s;

	int i = 0;
	int fd = open(argv[1], O_RDONLY);
	if (fd<0)
	 ft_putstr("fd non valid");
	map = ft_strdup("");
	s = get_next_line(fd);
	while (s)
	{
		map = ft_strjoin(map, s);
		if (!map)
			exit(1);
		free (s);
		s = get_next_line(fd);
		i++;
	}
	close (fd);
	str = ft_split(map, '\n');
	return (str);
}

void parcing(char **argv, t_ptr *data)
{
	data->tab = ft_read(argv);
	// data->tab = ft_strtrim(data->tab, '\n');
	ft_check_ber(argv[1]);
	ft_count(data);
	ft_check_one(data);
	ft_check_cote(data);
	ft_check(data);
}
// int hook(int key, t_ptr *data)
// {
// 	if (key == 53)
// 		exit(0);
// 	if (key == 13)
// 	{
// 		if (data->tab[data->pos_player.x - 1][data->pos_player.y] != '1')
// 		{

// 			data->img = mlx_xpm_file_to_image(data->mlx,"images/Player.xpm",&data->a,&data->b);
//             mlx_put_image_to_window(data->mlx,data->win,data->img,data->pos_player.y, data->pos_player.x);			
			
// 		}
// 	}
// 	return 1;
// }

int ad_img(t_ptr *data)
{
	draw_map_P(data);
	draw_map_0(data);
	draw_map_1(data);
	draw_map_C(data);
	draw_map_E(data);
	return (0);
}

int main(int argc , char **argv)
{
	t_ptr data;
	data.C = 0;
	data.moves = 0;
	parcing(argv, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,ft_strlen(data.tab[0]) * 40,ft_strlen_2d(data.tab) * 40,"so_long");
	mlx_loop_hook(data.mlx, &ad_img, &data);
	mlx_hook(data.win,2,0,&hook,&data);
	mlx_loop(data.mlx);
}