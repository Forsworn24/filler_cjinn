/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <cjinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 02:05:37 by cjinn             #+#    #+#             */
/*   Updated: 2020/02/06 18:12:29 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int check_piece(t_map *map, t_piece *p, int y, int x)
{
    int y1;
    int x1;

    y1 = 0;
    while (y1 < p->size_y)
    {
        x1 = 0;
        while (x1 < p->size_x)
        {
            if (y1 + y > map->size_y - 1 || x1 + x > map->size_x - 1)
                return (0);
            x1++;
        }
        y1++;
    }
    return (1);
}

int check_piece2(t_map *map, t_piece *p, int y, int x)
{
    int y1;
    int x1;
    int count;

    count = 0;
    y1 = 0;
    while (y1 < p->size_y)
    {
        x1 = 0;
        while (x1 < p->size_x)
        {
            if (p->p[y1][x1] == '*' && map->heat_map[y1 + y][x1 + x] == -1)
                return (0);
            if (p->p[y1][x1] == '*' && map->heat_map[y1 + y][x1 + x] == -2)
                count++;
            x1++;
        }
        y1++;
    }
    if (count == 1)
        return (1);
    return (0);
}

int play(t_map *map, t_piece *p)
{
    int y;
    int x;

    y = 0;
    while (y < map->size_y)
    {
        x = 0;
        while (x < map->size_x)
        {
            if (check_piece(map, p, y, x) == 1)
            {
                if (check_piece2(map, p, y, x) == 1)
                {
                    map->final_x = x;
                    map->final_y = y;
                    //print_result(map);
                    return (1);
                }
            }
            x++;
        }
        y++;
    }
    return (0);
}