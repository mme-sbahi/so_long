/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:08:44 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/23 13:08:38 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
# include <mlx.h> 

void ft_check_ber(char *str, t_ptr *data)
{
	char *s1 = ft_substr(str,ft_strlen(str) - 4,4);
	if (ft_strcmp(s1,".ber") != 0)
	{
		free(s1);
		ft_error("check map's name ", data->tab);
	}
	free(s1);
}
void	ft_check(t_ptr *data)
{
	int i;
	int j;
	int p;
	int e;

	i = -1;
	p = 0;
	e = 0;
	while (data->tab[++i])
	{
		j = -1;
		while (data->tab[i][++j])
		{
			if (data->tab[i][j] != 'P' && data->tab[i][j] != 'E' &&
				data->tab[i][j] != 'C' && data->tab[i][j] != '1' &&
				data->tab[i][j] != '0')
				ft_error("ERROR : bad charachters", data->tab);
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
		}
	}
	if (p != 1 || e != 1 || data->C < 1)
		ft_error("map non valid", data->tab);
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
			ft_error("map non valid \n", data->tab);
		i++;
	}
	int s;
	s = ft_strlen(data->tab[0]) - 1;
	i = 0;
	while (data->tab[i][s] && i < j - 1 )
	{
		if (data->tab[i][s] != '1')
			ft_error("map non valid \n", data->tab);
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
			ft_error("map non valid\n", data->tab);
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
			ft_error("map non valid \n", data->tab);
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
			ft_error("map non valid\n", data->tab);
		j++;
	}
}
char **ft_read(char **argv)

{
	char *map;
	char **str;
	char	*s;

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
		if (s && s[0] == '\n')
		{
			free(s);
			ft_error("ERROR : map non valid",NULL);
		}
	}
	free(s);
	close (fd);
	str = ft_split(map, '\n');
	free(map);
	return (str);
}

// void ok(void)
// {
// 	system("leaks a.out");
// }

