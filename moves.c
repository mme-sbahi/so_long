/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:09 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/24 16:25:44 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook(int key, t_ptr *data)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		ft_w(data);
	if (key == 0)
		ft_a(data);
	if (key == 2)
		ft_d(data);
	if (key == 1)
		ft_s(data);
	return (0);
}

int	ft_w(t_ptr *data)
{
	if (data->tab[data->x - 1][data->y] == 'E' && data->c == 0)
	{
		ft_putstr ("bravoo!!");
		exit(0);
	}
	if (data->tab[data->x - 1][data->y] != '1' &&
		data->tab[data->x - 1][data->y] != 'E')
	{
		if (data->tab[data->x - 1][data->y] == 'C')
		{
			data->c--;
		}
		data->tab[data->x - 1][data->y] = 'P';
		data->tab[data->x][data->y] = '0';
		data->x--;
		data->moves++;
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	return (0);
}

int	ft_a(t_ptr*data)
{
	if (data->tab[data->x][data->y - 1] == 'E' && data->c == 0)
	{
		ft_putstr ("bravoo!!");
		exit(0);
	}
	if (data->tab[data->x][data->y - 1] != '1' &&
		data->tab[data->x][data->y - 1] != 'E')
	{
		if (data->tab[data->x][data->y - 1] == 'C')
			data->c--;
		data->tab[data->x][data->y - 1] = 'P';
		data->tab[data->x][data->y] = '0';
		data->y--;
		data->moves++;
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	return (0);
}

int	ft_d(t_ptr *data)
{	
	if (data->tab[data->x][data->y + 1] == 'E' && data->c == 0)
	{
		ft_putstr ("bravoo!!");
		exit(0);
	}
	if (data->tab[data->x][data->y + 1] != '1' &&
		data->tab[data->x][data->y + 1] != 'E')
	{
		if (data->tab[data->x][data->y + 1] == 'C')
			data->c--;
			data->tab[data->x][data->y + 1] = 'P';
		data->tab[data->x][data->y] = '0';
		data->y++;
		data->moves++;
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	return (0);
}

int	ft_s(t_ptr *data)
{	
	if (data->tab[data->x + 1][data->y] == 'E' && data->c == 0)
	{
		ft_putstr("bravoo!!");
		exit(0);
	}
	if (data->tab[data->x + 1][data->y] != '1' &&
		data->tab[data->x + 1][data->y] != 'E')
	{
		if (data->tab[data->x + 1][data->y] == 'C')
			data->c--;
		data->tab[data->x + 1][data->y] = 'P';
		data->tab[data->x][data->y] = '0';
		data->x++;
		data->moves++;
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
	return (0);
}
