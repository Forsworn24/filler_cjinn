/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <cjinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:35:09 by cjinn             #+#    #+#             */
/*   Updated: 2020/02/06 18:26:50 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void print_result(t_map *map)
{
    ft_putnbr(map->final_y);
    ft_putchar(' ');
    ft_putnbr(map->final_x);
    ft_putchar('\n');
}

void get_x_o(t_map *map)
{
    if (map->player == 1)
    {
        map->my = "Oo";
        map->en = "Xx";
    }
    if (map->player == 2)
    {
        map->my = "Xx";
        map->en = "Oo";
    }
    //printf("map->my = %s\n", map->my);
}

void get_player(t_map *map)
{
    char		*line;

	ft_get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && map->player == 0)
	{
		if (ft_strstr(line, "p2"))
			map->player = 2;
		if (ft_strstr(line, "p1"))
			map->player = 1;
		get_x_o(map);
	}
    ft_strdel(&line);
}

void init(t_map *map, t_piece *p)
{
    map->field = NULL;
    map->size_x = 0;
    map->size_y = 0;
    map->player = 0;
    map->heat_score = 0;
    p->size_x = 0;
    p->size_y = 0;
    map->final_x = 0;
    map->final_y = 0;
}

int main(void)
{
    t_map *map;
    t_piece *p;
    int     xx;

    int i = 0;
    map = (t_map*)malloc(sizeof(t_map));
    p = (t_piece*)malloc(sizeof(t_piece));
    init(map, p);
    get_player(map);
    xx = 0;
    //printf("%d %d\n", 8, 2);
    while (xx < 10)
    {
        read_map_and_piece(map, p);
        heat_map(map);
        if (play(map, p))
            print_result(map);
        xx++;
    }
    /*while (1)
    {
        while (read_map_and_piece(map, p))
        {
            heat_map(map);
            if (play(map, p))
            {
                print_result(map);
                xx = 1;
                break ;
            }
            else
                exit(1);
        }
        if (xx)
            break;
    }*/
    /*
    while (1)
    {
        read_map_and_piece(map, p);
        heat_map(map);
        if (play(map, p) == 1)
            print_result(map);
        exit(1)
    }*/
    //free_maps(map);
    //free_struct(map, p);
    return (0);
}