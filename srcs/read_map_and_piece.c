/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_and_piece.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <cjinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:17:04 by cjinn             #+#    #+#             */
/*   Updated: 2020/02/06 18:22:55 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void get_piece(t_piece *p)
{
    char *line;
    int i;

    p->p = (char **)malloc(sizeof(char *) * (p->size_y));
    i = 0;
    while (i < p->size_y)
    {
        ft_get_next_line(0, &line);
        p->p[i] = ft_strdup((const char *)line);
        i++;
        ft_strdel(&line);
    }
    i = 0;
    /*while (i < p->size_y)
    {
        printf("%s\n", p->p[i]);
        i++;
    }*/
}

void get_piece_size(t_piece *p, char *line)
{
    int i;
    int ch;

    i = 0;
    p->size_x = 0;
    p->size_y = 0;
    while (line[i])
    {
        ch = 0;
        while (line[i] >= 48 && line[i] <= 57)
        {
            ch = ch * 10 + line[i] - '0';
            i++;
        }
        if (p->size_y == 0)
            p->size_y = ch;
        else if (p->size_x == 0)
            p->size_x = ch;
        i++;
    }
    //printf("p->size_x = %d\n", p->size_x);
    //printf("p->size_y = %d\n", p->size_y);
    get_piece(p);
}

void get_map(t_map *map)
{
    char *line;
    int i;

    ft_get_next_line(0, &line);
    ft_strdel(&line);
    map->field = (char **)malloc(sizeof(char *) * (map->size_y));
    i = 0;
    while (i < map->size_y)
    {
        ft_get_next_line(0, &line);
        map->field[i] = ft_strdup((const char *)(&line[4]));
        ft_strdel(&line);
        i++;
    }
    i = 0;
    /*while (i < map->size_y)
    {
        printf("%s\n", map->field[i]);
        i++;
    }*/
}

void get_map_size(t_map *map, char *line)
{
    int i;
    int ch;

    i = 0;
    map->size_x = 0;
    map->size_y = 0;
    while (line[i])
    {
        ch = 0;
        while (line[i] >= 48 && line[i] <= 57)
        {
            ch = ch * 10 + line[i] - '0';
            i++;
        }
        if (map->size_y == 0)
            map->size_y = ch;
        else if (map->size_x == 0)
            map->size_x = ch;
        i++;
    }
   // printf("map->size_x = %d\n", map->size_x);
   // printf("map->size_y = %d\n", map->size_y);
    get_map(map);
}

int read_map_and_piece(t_map *map, t_piece *p)
{
    char *line;

    //p->p = NULL;
    while (ft_get_next_line(0, &line) > 0)
    {
        if (ft_strncmp(line, "Plateau", 6) == 0)
        {
            get_map_size(map, line);
            ft_strdel(&line);
        }
        else if (ft_strncmp(line, "Piece", 4) == 0)
        {
            get_piece_size(p, line);
            ft_strdel(&line);
            return (1);
        }
        else
            ft_strdel(&line);
    }
    return (0);
}