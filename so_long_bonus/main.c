/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 20:14:14 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/09 15:39:42 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (0);
	checkav(av[1]);
	parsing(&map, av[1]);
	system("leaks so_long");
	affiche(&map);
}
