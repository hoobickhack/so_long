/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:27:20 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/09 16:03:46 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	countmap(t_map *map, char *av)
{
	int		fd;
	char	*str;

	fd = open(av, O_RDONLY);
	map->countline = 0;
	str = get_next_line_bonus(fd);
	if (!str)
		writeerreur(0);
	map->countchara = ft_strlen(str) - 1;
	while (str)
	{
		map->countline++;
		free(str);
		str = get_next_line_bonus(fd);
	}
	close(fd);
}

void	copymap(t_map	*map, char	*av)
{
	int		fd;
	int		ligne;

	ligne = 0;
	fd = open(av, O_RDONLY);
	map->cpymap = malloc(sizeof(char *) * (map->countline + 1));
	if (!(map->cpymap))
		exit(EXIT_FAILURE);
	while (ligne < map->countline)
	{
		map->cpymap[ligne] = get_next_line_bonus(fd);
		ligne++;
	}
	map->cpymap[ligne] = 0;
	close(fd);
}

void	checkmap(t_map	*map)
{
	int	i;

	i = 0;
	while (map->cpymap[0][i] != '\n')
	{
		if (map->cpymap[0][i] != '1')
		{
			freecpy(map);
			writeerreur(3);
		}
		i++;
	}
	i = 0;
	while (map->cpymap[map->countline - 1][i] != '\n')
	{
		if (map->cpymap[map->countline - 1][i] != '1')
		{
			freecpy(map);
			writeerreur(3);
		}
		i++;
	}
}

void	checkmap2(t_map *map)
{
	int	j;
	int	i;

	j = -1;
	while (++j < map->countline - 1)
	{
		i = -1;
		while (++i < map->countchara - 1)
		{
			if ((map->cpymap[j][i] != '1') && (map->cpymap[j][i] != '0') &&
			(map->cpymap[j][i] != 'C') && (map->cpymap[j][i] != 'E') &&
			(map->cpymap[j][i] != 'P') && (map->cpymap[j][i] != 'M'))
			{
				freecpy(map);
				writeerreur(3);
			}
		}
		if ((map->cpymap[j][0] != '1') ||
		(map->cpymap[j][map->countchara - 1] != '1'))
		{
			freecpy(map);
			writeerreur(3);
		}
	}
}

void	writeerreur(int a)
{
	if (a == 0)
		ft_printf("Error\n Vérifie ton fichier");
	if (a == 1)
		ft_printf("Error\n Et non c'est un dossier");
	if (a == 2)
		ft_printf("Error\n Vérifie ton .ber");
	if (a == 3)
		ft_printf("Error\n Vérifie ta Map");
	if (a == 4)
		ft_printf("Error\n Vérifie ton chemin");
	if (a == 5)
		ft_printf("Error\n Erreur avec la MLX");
	if (a == 6)
		ft_printf("Game Over");
	exit(EXIT_FAILURE);
}
