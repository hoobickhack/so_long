/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:19:35 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/09 16:52:36 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parsing(t_map *map, char *av)
{
	int	a;
	int	b;
	int	j;

	j = 0;
	a = 0;
	b = 0;
	countmap(map, av);
	copymap(map, av);
	checkmap(map);
	checkmap2(map);
	checkmap3(map);
	checkmap4(map);
	checkrectangle(map);
	cpypass(map, a, b, j);
}

void	position(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->countline - 1)
	{
		i = -1;
		while (++i < map->countchara - 1)
		{
			if (map->cpymap[j][i] == 'P')
			{
				map->pi = i;
				map->pj = j;
			}
		}
	}
}

void	checkc(t_map *map)
{
	int	i;
	int	j;

	map->c = 0;
	j = -1;
	while (map->cpymap[++j])
	{
		i = -1;
		while (map->cpymap[j][++i])
		{
			if (map->cpymap[j][i] == 'C')
				map->c++;
		}
	}
}

int	ft_exit(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	exit(0);
	return (0);
}
