/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jeu2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:17:51 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/05 15:47:29 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_exit(int key, t_map *map)
{
	checkc(map);
	if (key == 53)
		exit(0);
}

void	key0(int key, t_map *map)
{
	if ((key == 0) && (map->cpymap[map->pj][map->pi - 1] != '1'))
	{
		if (map->c == 0)
		{
			if (map->cpymap[map->pj][map->pi - 1] == 'E' && map->c == 0)
				exit(0);
			map->cpymap[map->pj][map->pi] = '0';
			map->cpymap[map->pj][map->pi - 1] = 'P';
			map->key++;
			ft_printf("%d\n", map->key);
		}
		if (map->c != 0 && (map->cpymap[map->pj][map->pi - 1] != 'E'))
		{
			map->cpymap[map->pj][map->pi] = '0';
			map->cpymap[map->pj][map->pi - 1] = 'P';
			map->key++;
			ft_printf("%d\n", map->key);
		}
	}
}

void	key2(int key, t_map *map)
{
	if ((key == 2) && (map->cpymap[map->pj][map->pi + 1] != '1'))
	{
		if (map->c == 0)
		{
			if (map->cpymap[map->pj][map->pi + 1] == 'E' && map->c == 0)
				exit(0);
			map->cpymap[map->pj][map->pi] = '0';
			map->cpymap[map->pj][map->pi + 1] = 'P';
			map->key++;
			ft_printf("%d\n", map->key);
		}
		if (map->c != 0 && (map->cpymap[map->pj][map->pi + 1] != 'E'))
		{
			map->cpymap[map->pj][map->pi] = '0';
			map->cpymap[map->pj][map->pi + 1] = 'P';
			map->key++;
			ft_printf("%d\n", map->key);
		}
	}
}

void	key1(int key, t_map *map)
{
	if ((key == 1) && (map->cpymap[map->pj + 1][map->pi] != '1'))
	{
		if (map->c == 0)
		{
			if (map->cpymap[map->pj + 1][map->pi] == 'E' && map->c == 0)
				exit(0);
			map->cpymap[map->pj][map->pi] = '0';
			map->cpymap[map->pj + 1][map->pi] = 'P';
			map->key++;
			ft_printf("%d\n", map->key);
		}
		if (map->c != 0 && (map->cpymap[map->pj + 1][map->pi] != 'E'))
		{
			map->cpymap[map->pj][map->pi] = '0';
			map->cpymap[map->pj + 1][map->pi] = 'P';
			map->key++;
			ft_printf("%d\n", map->key);
		}
	}
}

void	key13(int key, t_map *map)
{
	if ((key == 13) && (map->cpymap[map->pj - 1][map->pi] != '1'))
	{
		if (map->c == 0)
		{
			if (map->cpymap[map->pj - 1][map->pi] == 'E' && map->c == 0)
				exit(0);
			map->cpymap[map->pj][map->pi] = '0';
			map->cpymap[map->pj - 1][map->pi] = 'P';
			map->key++;
			ft_printf("%d\n", map->key);
		}
		if (map->c != 0 && (map->cpymap[map->pj - 1][map->pi] != 'E'))
		{
			map->cpymap[map->pj][map->pi] = '0';
			map->cpymap[map->pj - 1][map->pi] = 'P';
			map->key++;
			ft_printf("%d\n", map->key);
		}
	}
}
