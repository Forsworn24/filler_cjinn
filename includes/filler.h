/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjinn <cjinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:36:16 by cjinn             #+#    #+#             */
/*   Updated: 2020/02/06 06:06:44 by cjinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILLER_H
# define FILLER_H
#include "../libft_cjinn/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_map
{
    char **field;
    int **heat_map;
    int size_x;
    int size_y;
    int player;
    char *en;
    char *my;
    int heat_score;
    int final_x;
    int final_y;
}               t_map;

typedef struct s_piece
{
    char **p;
    int size_x;
    int size_y;
}               t_piece;

int read_map_and_piece(t_map *map, t_piece *p);
int heat_map(t_map *map);
void free_struct(t_map *map, t_piece *p);
int free_maps(t_map *map);
int play(t_map *map, t_piece *p);
void print_result(t_map *map);
int no_play1(t_map *map, t_piece *p);

#endif