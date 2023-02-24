/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesbahi <mmesbahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:58:46 by mmesbahi          #+#    #+#             */
/*   Updated: 2023/02/24 19:04:33 by mmesbahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_one(t_ptr	*data)
{
	int	i;
	int	j;

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
