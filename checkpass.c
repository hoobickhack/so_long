/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:52:44 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/09 16:50:50 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cpypass(t_map *map, int a, int b, int j)
{
	char	**cpytest;
	char	**cpycom;

	j = -1;
	cpycom = malloc(sizeof(char *) * (map->countline + 1));
	cpytest = malloc(sizeof(char *) * (map->countline + 1));
	if ((!(cpytest)) || (!(cpycom)))
		exit(EXIT_FAILURE);
	while (map->cpymap[++j])
	{
		cpycom[j] = ft_strdup(map->cpymap[j]);
		cpytest[j] = ft_strdup(map->cpymap[j]);
	}
	cpytest[j] = 0 ;
	cpycom[j] = 0;
	checkcom (cpycom, a, b);
	checkcom2(cpycom);
	checkbis(cpytest);
	checktab(cpytest);
}

void	checkbis(char **tab)
{
	int	i;
	int	j;

	j = -1;
	while (tab[++j])
	{
		i = 0;
		while (tab[j][i++])
		{
			if ((tab[j][i] == 'P') || (tab[j][i] == 'G'))
			{
				tab[j][i] = 'X';
				if (tab[j][i - 1] != '1' && (tab[j][i - 1] != 'X'))
					tab[j][i - 1] = 'G';
				if (tab[j][i + 1] != '1' && (tab[j][i + 1] != 'X'))
					tab[j][i + 1] = 'G';
				if (tab[j - 1][i] != '1' && (tab[j - 1][i] != 'X'))
					tab[j - 1][i] = 'G';
				if (tab[j + 1][i] != '1' && (tab[j + 1][i] != 'X'))
					tab[j + 1][i] = 'G';
				j = 0;
			}
		}
	}
}

void	checktab(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if ((tab[j][i] == 'C') || (tab[j][i] == 'E'))
			{
				writeerreur(4);
			}
			i++;
		}
		free(tab[j]);
		j++;
	}
	free(tab);
}

void	checkcom(char **tab, int j, int i)
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
				(tab[j][i - 1] != 'E'))
					tab[j][i - 1] = 'G';
				if (tab[j][i + 1] != '1' && (tab[j][i + 1] != 'X') && 
				(tab[j][i + 1] != 'E'))
					tab[j][i + 1] = 'G';
				if (tab[j - 1][i] != '1' && (tab[j - 1][i] != 'X') && 
				(tab[j - 1][i] != 'E'))
					tab[j - 1][i] = 'G';
				if (tab[j + 1][i] != '1' && (tab[j + 1][i] != 'X') &&
				(tab[j + 1][i] != 'E'))
					tab[j + 1][i] = 'G';
				j = 0;
			}
		}
	}
}

void	checkcom2(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == 'C')
			{
				writeerreur(4);
			}
			i++;
		}
		free(tab[j]);
		j++;
	}
	free(tab);
}
