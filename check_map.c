/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:08:44 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/24 18:22:34 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	ft_check_ber(char *str, t_ptr *data)
{
	char	*s1;

	s1 = ft_substr(str, ft_strlen(str) - 4, 4);
	if (ft_strcmp(s1, ".ber") != 0)
	{
		free(s1);
		ft_error("check map's name ", data->tab);
	}
	free(s1);
}

void	ft_count(t_ptr *data)
{
	int	i;
	int	j;
	int	x;

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

void	ft_error_free(char *s, char *map)
{
	free(s);
	free(map);
	ft_error("ERROR : map non valid", NULL);
}

char	**ft_read(char **argv)
{
	char	*map;
	char	**str;
	char	*s;
	int		fd;

	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		ft_putstr ("fd non valid");
	map = ft_strdup("");
	s = get_next_line(fd);
	while (s)
	{
		if (s && s[0] == '\n')
			ft_error_free(s, map);
		map = ft_strjoin(map, s);
		if (!map)
			exit(1);
		free (s);
		s = get_next_line(fd);
	}
	free(s);
	close (fd);
	str = ft_split(map, '\n');
	return (free(map), str);
}
