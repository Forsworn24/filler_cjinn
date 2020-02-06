/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <cjinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:44:17 by cjinn             #+#    #+#             */
/*   Updated: 2020/02/06 17:18:19 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int ft_check_en(t_map *map, int y, int x)
{
    if (map->field[y][x] == map->en[0] || map->field[y][x] == map->en[1])
        return (-1);
    if (map->field[y][x] == map->my[0] || map->field[y][x] == map->my[1])
        return (-2);
    return (0);
}

static void first_elem(t_map *map, int i, int j)
{
    if (j + 1 < map->size_x && ft_check_en(map, i, j + 1) == -1)
        map->heat_map[i][j] = 1;
    if (i + 1 < map->size_y && ft_check_en(map, i + 1, j) == -1)
        map->heat_map[i][j] = 1;
    if (i + 1 < map->size_y && j + 1 < map->size_x && ft_check_en(map, i + 1, j + 1) == -1)
        map->heat_map[i][j] = 1;
    if (j + 1 < map->size_x && i - 1 >= 0 &&  ft_check_en(map, i - 1, j + 1) == -1)
        map->heat_map[i][j] = 1;
    if (j - 1 >= 0 && ft_check_en(map, i, j - 1) == -1)
        map->heat_map[i][j] = 1;
    if (i - 1 >= 0 && ft_check_en(map, i - 1, j) == -1)
        map->heat_map[i][j] = 1;
    if (j - 1 >= 0 && i - 1 >= 0 && ft_check_en(map, i - 1, j - 1) == -1)
        map->heat_map[i][j] = 1;
    if (j - 1 >= 0 && i + 1 < map->size_y && ft_check_en(map, i + 1, j - 1) == -1)
        map->heat_map[i][j] = 1;
}   

void put_heat1(t_map *map)
{
    int y;
    int x;

    y = 0;
    while (y < map->size_y)
    {
        x = 0;
        while (x < map->size_x)
        {
            if (map->heat_map[y][x] == 0)
                first_elem(map, y, x);
            x++;
        }
        y++;
    }
}

void put_heat(t_map *map, int i, int x, int y)
{
    if (x + 1 < map->size_x && map->heat_map[y][x + 1] == i)
		map->heat_map[y][x] = i + 1;
	if (y + 1 < map->size_y && map->heat_map[y + 1][x] == i)
		map->heat_map[y][x] = i + 1;
	if (x + 1 < map->size_x && y + 1 < map->size_y && map->heat_map[y + 1][x + 1] == i)
		map->heat_map[y][x] = i + 1;
	if (x + 1 < map->size_x && y - 1 >= 0 && map->heat_map[y - 1][x + 1] == i)
		map->heat_map[y][x] = i + 1;
	if (x - 1 >= 0 && map->heat_map[y][x - 1] == i)
		map->heat_map[y][x] = i + 1;
	if (y - 1 >= 0 && map->heat_map[y - 1][x] == i)
		map->heat_map[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && map->heat_map[y - 1][x - 1] == i)
		map->heat_map[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < map->size_y && map->heat_map[y + 1][x - 1] == i)
		map->heat_map[y][x] = i + 1;
}

void create_heat_map(t_map *map)
{
    int x;
    int y;
    int i;

    x = 0;
    y = 0;
    i = 1;
    while (i < map->size_x)
    {
        while (y < map->size_y)
        {
            while (x < map->size_x)
            {
                if (map->heat_map[y][x] == 0)
                    put_heat(map, i, x, y);
                x++;
            }
            x = 0;
            y++;
        }
        x = 0;
        y = 0;
        i++;
    }
}

int heat_map(t_map *map)
{
    int x;
    int y;

    y = 0;
    x = map->size_x;
    map->heat_map = (int **)malloc(sizeof(int*) * map->size_y);
    while (y < map->size_y)
    {
        map->heat_map[y] = (int *)malloc(sizeof(int) * x);
        y++;
    }
    y = 0;
    x = 0;
    while (y < map->size_y)
    {
        x = 0;
        while (x < map->size_x)
        {
            if (map->field[y][x] == '.')
                map->heat_map[y][x] = 0;
            else if (ft_check_en(map, y, x) == -1)
                map->heat_map[y][x] = -1;
            else if (ft_check_en(map, y, x) == -2)
                map->heat_map[y][x] = -2;
            x++;
        }
        y++;
    }
    put_heat1(map);
    create_heat_map(map);
    y = 0;
    x = 0;
    /*while (y < map->size_y)
    {
        x = 0;
        while (x < map->size_x)
        {
            printf(" %2d", map->heat_map[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }*/
    return (1);
}