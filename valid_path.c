/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:47:59 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/24 19:15:25 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	**dup_2d_arr(char **arr)
{
	int		i;
	char	**tmp;

	i = -1;
	while (arr[i])
	{
		i++;
	}
	tmp = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (arr[++i])
		tmp[i] = ft_strdup(arr[i]);
	tmp[i] = NULL;
	return (tmp);
}

void	flood_fill_e(char **arr, int x, int y)
{
	if (arr[x][y] != '1' && arr[x][y] != '+')
	{
		arr[x][y] = '+';
		flood_fill_e(arr, x + 1, y);
		flood_fill_e(arr, x - 1, y);
		flood_fill_e(arr, x, y + 1);
		flood_fill_e(arr, x, y - 1);
	}
}

void	flood_fill_c(char **arr, int x, int y)
{
	if (arr[x][y] != '1' && arr[x][y] != '+' && arr[x][y] != 'E')
	{
		arr[x][y] = '+';
		flood_fill_c(arr, x, y + 1);
		flood_fill_c(arr, x, y - 1);
		flood_fill_c(arr, x + 1, y);
		flood_fill_c(arr, x - 1, y);
	}
}

int	check_flood_fill(t_ptr *data)
{
	char	**tmp;
	int		i;
	int		count;

	count = 0;
	i = -1;
	tmp = dup_2d_arr(data->tab);
	flood_fill_c(tmp, data->x, data->y);
	while (tmp[++i])
		if (ft_strchr(tmp[i], 'C'))
			count++;
	ft_free(tmp, ft_strlen_2d(tmp) - 1);
	if (count != 0)
		ft_error("error backtracking\n", data->tab);
	count = 0;
	i = -1;
	tmp = dup_2d_arr(data->tab);
	flood_fill_e(tmp, data->x, data->y);
	while (tmp[++i])
		if (ft_strchr(tmp[i], 'E'))
			count++;
	ft_free(tmp, ft_strlen_2d(tmp) - 1);
	if (count != 0)
		ft_error("error backtracking\n", data->tab);
	return (1);
}
