/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:09 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/20 19:27:48 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int hook(int key, t_ptr *data)
{
	if (key == 53)
		exit(0);
	if (key == 13)
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
			// ft_putstr("moves : ");
			// ft_putnbr_fd(data->moves,1);
			// ft_putstr("\n");
		}
	}
	if (key == 0)
	{
		if (data->tab[data->pos_player.x][data->pos_player.y - 1] == 'E' && data->C == 0)
			exit(0);
		if (data->tab[data->pos_player.x][data->pos_player.y - 1] != '1' && data->tab[data->pos_player.x][data->pos_player.y - 1] != 'E')
		{
			if (data->tab[data->pos_player.x][data->pos_player.y - 1] == 'C')
			{
				data->C--;
			}
            data->tab[data->pos_player.x][data->pos_player.y - 1] = 'P';
            data->tab[data->pos_player.x][data->pos_player.y] = '0';
			data->pos_player.y--;
			// ft_putstr("moves : ");
			// ft_putnbr_fd(data->moves,1);
			// ft_putstr("\n");
		}
	}
	if (key == 2)
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
			// ft_putstr("moves : ");
			// ft_putnbr_fd(data->moves,1);
			// ft_putstr("\n");
		}
	}
	if (key == 1)
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
			// ft_putstr("moves : ");
			// ft_putnbr_fd(data->moves,1);
			// ft_putstr("\n");
		}
	}
	return 0;
}