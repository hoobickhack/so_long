/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jeu3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:01:00 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/05 16:15:24 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->img_ptr_s, i * 64, j * 64);
	if (map->cpymap[j][i] == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_p, i * 64, j * 64);
	if (map->cpymap[j][i] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_m, i * 64, j * 64);
	if (map->cpymap[j][i] == 'E' && map->c != 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_e, i * 64, j * 64);
	else if (map->cpymap[j][i] == 'E' && map->c == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_e2, i * 64, j * 64);
	if (map->cpymap[j][i] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_c, i * 64, j * 64);
}
