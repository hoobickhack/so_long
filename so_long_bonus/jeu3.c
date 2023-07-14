/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jeu3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:01:00 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/09 16:35:31 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_map *map, int i, int j)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->img_ptr_s, i * 64, j * 64);
	printperso(map, i, j);
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
	if (map->cpymap[j][i] == 'M')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_mo, i * 64, j * 64);
	mlx_string_put(map->mlx, map->mlx_win, 1, 1, 0x000B00, ft_itoa(map->key));
}

void	printperso(t_map *map, int i, int j)
{
	if ((map->cpymap[j][i] == 'P') && (map->p == 0))
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_p, i * 64, j * 64);
	if ((map->cpymap[j][i] == 'P') && (map->p == 1))
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_pg, i * 64, j * 64);
	if ((map->cpymap[j][i] == 'P') && (map->p == 2))
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_pd, i * 64, j * 64);
	if ((map->cpymap[j][i] == 'P') && (map->p == 3))
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_pa, i * 64, j * 64);
	if ((map->cpymap[j][i] == 'P') && (map->p == 4))
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->img_ptr_pdo, i * 64, j * 64);
}

void	fin(int a)
{
	if (a == 0)
		ft_printf("Finish\n");
	if (a == 1)
		ft_printf("Game Over\n");
	exit(0);
}

void	checkmonstre(char **tab, int j, int i)
{
	j = -1;
	while (tab[++j])
	{
		i = 0;
		while (tab[j][i++])
		{
			if ((tab[j][i] == 'P') || (tab[j][i] == 'G'))
			{
				tab[j][i] = 'X';
				if (tab[j][i - 1] != '1' && (tab[j][i - 1] != 'X') && 
				(tab[j][i - 1] != 'M'))
					tab[j][i - 1] = 'G';
				if (tab[j][i + 1] != '1' && (tab[j][i + 1] != 'X') && 
				(tab[j][i + 1] != 'M'))
					tab[j][i + 1] = 'G';
				if (tab[j - 1][i] != '1' && (tab[j - 1][i] != 'X') && 
				(tab[j - 1][i] != 'M'))
					tab[j - 1][i] = 'G';
				if (tab[j + 1][i] != '1' && (tab[j + 1][i] != 'X') &&
				(tab[j + 1][i] != 'M'))
					tab[j + 1][i] = 'G';
				j = 0;
			}
		}
	}
}
