/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:19:24 by isouaidi          #+#    #+#             */
/*   Updated: 2023/07/09 18:17:16 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# include "./libft/inc/libft.h"
# include "./libft/inc/ft_printf.h"
# include "./libft/inc/get_next_line_bonus.h"

typedef struct s_map
{
	char			**cpymap;
	int				pj;
	int				pi;
	int				countchara;
	int				countline;
	void			*img_ptr_p;
	void			*img_ptr_m;
	void			*img_ptr_c;
	void			*img_ptr_s;
	void			*img_ptr_e;
	void			*img_ptr_e2;
	void			*img_ptr_mo;
	void			*img_ptr_pg;
	void			*img_ptr_pd;
	void			*img_ptr_pdo;
	void			*img_ptr_pa;
	void			*mlx;
	void			*mlx_win;
	int				key;
	int				c;
	int				p;
}	t_map;

void	parsing(t_map *map, char *av);
void	countmap(t_map *tmap, char *av);
void	copymap(t_map	*tmap, char	*av);
void	checkmap(t_map	*tmap);
void	checkmap2(t_map *tmap);
void	checkmap3(t_map *map);
void	checkmap4(t_map *map);
void	writeerreur(int a);
void	checkrectangle(t_map *map);
void	checkav(char *av);
void	cpypass(t_map *map, int a, int b, int j);
void	checkbis(char **tab);
void	checktab(char **tab);
void	freecpy(t_map *map);
void	affiche(t_map *map);
int		graph(t_map *map, int i, int j);
void	img(t_map *map);
void	position(t_map *map);
int		even(int key, t_map *map);
void	mlx_exit(int key, t_map *map);
void	key0(int key, t_map *map);
void	key2(int key, t_map *map);
void	key1(int key, t_map *map);
void	key13(int key, t_map *map);
void	checkc(t_map *map);
void	put_image(t_map *map, int i, int j);
void	checkcom(char **tab, int j, int i);
void	checkcom2(char **tab);
int		ft_exit(t_map *map);
void	printperso(t_map *map, int i, int j);
void	fin(int a);
void	checkmonstre(char **tab, int j, int i);
#endif
