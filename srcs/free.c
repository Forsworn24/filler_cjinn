/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <cjinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:06:27 by cjinn             #+#    #+#             */
/*   Updated: 2020/02/05 22:11:05 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	free_heat_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_y)
		free(map->heat_map[i++]);
	free(map->heat_map);
}

static void	free_piece(t_piece *p)
{
	int	i;

	i = 0;
	while (i < p->size_y)
		free(p->p[i++]);
	free(p->p);
}

int free_maps(t_map *map)
{
    int	i;

	i = 0;
	while (i < map->size_y)
	{
		free(map->field[i]);
		free(map->heat_map[i]);
		i++;
	}
	free(map->field);
	free(map->heat_map);
	return (1);
}

void free_struct(t_map *map, t_piece *p)
{
    free_heat_map(map);
    free_piece(p);
}