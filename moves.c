/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:09 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/22 20:00:51 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int hook(int key, t_ptr *data)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		ft_W(data);
	if (key == 0)
		ft_A(data);
	if (key == 2)
		ft_D(data);
	if (key == 1)
		ft_S(data);
	return (0);
}
int ft_W(t_ptr *data)
{
		if (data->tab[data->pos_player.x - 1][data->pos_player.y ] == 'E' && data->C == 0)
			exit(0);
		if (data->tab[data->pos_player.x - 1][data->pos_player.y] != '1' && data->tab[data->pos_player.x - 1][data->pos_player.y ] != 'E')
		{
			if (data->tab[data->pos_player.x - 1][data->pos_player.y] == 'C')
			{
				data->C--;
			}
            data->tab[data->pos_player.x - 1][data->pos_player.y] = 'P';
            data->tab[data->pos_player.x][data->pos_player.y] = '0';
			data->pos_player.x--;
			data->moves++;
			ft_putnbr_fd(data->moves,1);
			write(1,"\n",1);
		}
		return (0);
}
int ft_A(t_ptr*data)
{	
		if (data->tab[data->pos_player.x][data->pos_player.y - 1] == 'E' && data->C == 0)
			{
				ft_putstr ("rb7tsiiii");
				exit(0);
			}
		if (data->tab[data->pos_player.x][data->pos_player.y - 1] != '1' && data->tab[data->pos_player.x][data->pos_player.y - 1] != 'E')
		{
			if (data->tab[data->pos_player.x][data->pos_player.y - 1] == 'C')
			{
				data->C--;
			}
            data->tab[data->pos_player.x][data->pos_player.y - 1] = 'P';
            data->tab[data->pos_player.x][data->pos_player.y] = '0';
			data->pos_player.y--;
			data->moves++;
			ft_putnbr_fd(data->moves,1);
			write(1,"\n",1);
		}
	return (0);
	}
int ft_D(t_ptr *data)
{	
		if (data->tab[data->pos_player.x][data->pos_player.y + 1] == 'E' && data->C == 0)
			exit(0);
		if (data->tab[data->pos_player.x][data->pos_player.y + 1] != '1' && data->tab[data->pos_player.x][data->pos_player.y + 1] != 'E')
		{
			if (data->tab[data->pos_player.x][data->pos_player.y + 1] == 'C')
			{
				data->C--;
			}
            data->tab[data->pos_player.x][data->pos_player.y + 1] = 'P';
            data->tab[data->pos_player.x][data->pos_player.y] = '0';
			data->pos_player.y++;
			data->moves++;
			ft_putnbr_fd(data->moves,1);
			write(1,"\n",1);
		}
	return (0);
	}
int ft_S(t_ptr *data)
{	
		if (data->tab[data->pos_player.x + 1][data->pos_player.y] == 'E' && data->C == 0)
			exit(0);
		if (data->tab[data->pos_player.x + 1][data->pos_player.y] != '1' && data->tab[data->pos_player.x + 1][data->pos_player.y] != 'E')
		{
			if (data->tab[data->pos_player.x + 1][data->pos_player.y] == 'C')
			{
				data->C--;
			}
            data->tab[data->pos_player.x + 1][data->pos_player.y] = 'P';
            data->tab[data->pos_player.x][data->pos_player.y] = '0';
			data->pos_player.x++;
			data->moves++;
			ft_putnbr_fd(data->moves,1);
			write(1,"\n",1);
		}
	return 0;
}
