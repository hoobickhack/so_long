/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:16:21 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/05 14:38:15 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkmap3(t_map *map)
{
	int	j;
	int	i;
	int	c;
	int	e;

	e = 0;
	c = 0;
	j = -1;
	while (map->cpymap[++j])
	{
		i = 0;
		while (map->cpymap[j][i])
		{
			if (map->cpymap[j][i] == 'C')
				c++;
			if (map->cpymap[j][i] == 'E')
				e++;
			i++;
		}
	}
	if ((c == 0) || (e != 1))
	{
		freecpy(map);
		writeerreur(3);
	}
}

void	checkmap4(t_map *map)
{
	int	j;
	int	i;
	int	p;

	p = 0;
	j = 0;
	while (map->cpymap[j])
	{
		i = 0;
		while (map->cpymap[j][i])
		{
			if (map->cpymap[j][i] == 'P')
				p++;
			i++;
		}
		j++;
	}
	if (p != 1)
	{
		freecpy(map);
		writeerreur(3);
	}
}

void	checkrectangle(t_map *map)
{
	int	j;

	j = 0;
	while (map->cpymap[j + 1])
	{
		if ((map->cpymap[j][map->countchara]) !=
		(map->cpymap[j + 1][map->countchara]))
		{
			freecpy(map);
			writeerreur(3);
		}
		j++;
		if (map->cpymap[map->countline - 1][map->countchara] !=
		map->cpymap[map->countline - 2][map->countchara])
		{
			freecpy(map);
			writeerreur(3);
		}
	}
}

void	checkav(char *av)
{
	int	i;

	if (open(av, O_DIRECTORY) != -1)
		writeerreur(1);
	if (open(av, O_RDONLY) == -1)
		writeerreur(0);
	i = ft_strlen(av);
	i -= 4;
	if (i < 1)
		writeerreur(2);
	if (ft_strncmp(&av[i], ".ber", 4))
		writeerreur(2);
}

void	freecpy(t_map *map)
{
	int	j;

	j = 0;
	while (map->cpymap[j])
	{
		free(map->cpymap[j]);
		j++;
	}
	free(map->cpymap);
}
