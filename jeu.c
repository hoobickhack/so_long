/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jeu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:37:32 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/05 15:57:38 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_img(t_map *map, char *name)
{
	void	*img_ptr;
	int		i;

	img_ptr = mlx_xpm_file_to_image(map->mlx, name, &i, &i);
	if (!img_ptr)
		writeerreur(5);
	return (img_ptr);
}

void	img(t_map *map)
{
	map->img_ptr_p = get_img(map, "./xpm/persofacet.xpm");
	map->img_ptr_s = get_img(map, "./xpm/sol.xpm");
	map->img_ptr_m = get_img(map, "./xpm/1.xpm");
	map->img_ptr_e = get_img(map, "./xpm/fin.xpm");
	map->img_ptr_c = get_img(map, "./xpm/diamond.xpm");
	map->img_ptr_e2 = get_img(map, "./xpm/fin2.xpm");
}

void	affiche(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, ((map->countchara) * 64),
			(map->countline) * 64, "MinTess");
	img(map);
	checkc(map);
	mlx_loop_hook(map->mlx, &graph, map);
	mlx_hook(map->mlx_win, 2, 0, &even, map);
	mlx_hook(map->mlx_win, 17, 0, &ft_exit, map);
	mlx_loop(map->mlx);
}

int	graph(t_map *map, int i, int j)
{
	j = -1;
	while (map->cpymap[++j])
	{
		i = -1;
		while (map->cpymap[j][++i])
		{
			put_image(map, i, j);
		}
	}
	return (0);
}

int	even(int key, t_map *map)
{
	mlx_exit(key, map);
	position(map);
	key0(key, map);
	key2(key, map);
	key1(key, map);
	key13(key, map);
	checkc(map);
	return (0);
}
