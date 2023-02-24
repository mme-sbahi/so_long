/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:58:59 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/24 19:02:15 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*ft_strdup(char *source)
{
	char	*p;
	int		i;

	p = (char *)malloc(ft_strlen(source) + 1 * sizeof(char));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (source[i])
	{
		p[i] = source[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_error(char *s, char **ss)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (2, &s[i], 1);
		i++;
	}
	if (ss)
		ft_free(ss, ft_strlen_2d(ss));
	exit (1);
}

void	ft_check_charachters(t_ptr *data, int i, int j)
{
	if (data->tab[i][j] != 'P' && data->tab[i][j] != 'E' &&
		data->tab[i][j] != 'C' && data->tab[i][j] != '1' &&
		data->tab[i][j] != '0')
		ft_error("ERROR : bad charachters", data->tab);
}

void	ft_check(t_ptr *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->tab[++i])
	{
		j = -1;
		while (data->tab[i][++j])
		{
			ft_check_charachters (data, i, j);
			if (data->tab[i][j] == 'P')
			{
				data->x = i;
				data->y = j;
				data->p++;
			}
			if (data->tab[i][j] == 'E')
				data->e++;
			if (data->tab[i][j] == 'C')
				data->c++;
		}
	}
	if (data->p != 1 || data->e != 1 || data->c < 1)
		ft_error ("map non valid", data->tab);
}

void	ft_check_cote(t_ptr *data)
{
	int	i;
	int	j;
	int	s;

	i = 1;
	j = 0;
	while (data->tab[j])
		j++;
	while (data->tab[i][0] && i < j - 1)
	{
		if (data->tab[i][0] != '1')
			ft_error ("map non valid \n", data->tab);
		i++;
	}
	s = ft_strlen(data->tab[0]) - 1;
	i = 0;
	while (data->tab[i][s] && i < j - 1)
	{
		if (data->tab[i][s] != '1')
			ft_error("map non valid \n", data->tab);
		i++;
	}
}
