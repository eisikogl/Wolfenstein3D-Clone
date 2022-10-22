/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calion <calion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:19:54 by calion            #+#    #+#             */
/*   Updated: 2022/09/26 22:08:22 by calion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void read_map(t_map *call_map)
{
    int fd;
    fd = open(call_map->map_path,O_RDONLY);
    char *line = get_next_line(fd);
    char *parsed_line;
    int i;
    call_map->floor_color = malloc(sizeof(int) * 3);
    call_map->ceiling_color = malloc(sizeof(int) * 3);
    while(line)
    {
        if(!ft_strncmp(line,"NO",2))
        {
            parsed_line = ft_strchr(line,'.');
            call_map->north_texture_path = parsed_line;
        }
        else if(!ft_strncmp(line,"SO",2))
        {
            parsed_line = ft_strchr(line,'.');
            call_map->south_texture_path = parsed_line;
        }
        else if(!ft_strncmp(line,"WE",2))
        {
            parsed_line = ft_strchr(line,'.');
            call_map->west_texture_path = parsed_line;
        }
        else if(!ft_strncmp(line,"EA",2))
        {
            parsed_line = ft_strchr(line,'.');
            call_map->east_texture_path = parsed_line;
        }
        else if(!ft_strncmp(line,"F",1))
        {
            int j;
            int start;
            int end;
            char *number;
            int numberato;
            j = 0;
            i = 0;
            while (line[i] != '\n')
            {
                while(ft_isdigit(line[i]) == 0)
                    i++;
                start = i;
                while(ft_isdigit(line[i]) == 1)
                    i++;
                end = i;
                number = ft_substr(line,start,end-start);
                numberato = ft_atoi(number);
                call_map->floor_color[j] = numberato;
                j++;
            }
            
        }
        else if(!ft_strncmp(line,"C",1))
        {
            int j;
            int start;
            int end;
            char *number;
            int numberato;
            j = 0;
            i = 0;
            while (line[i] != '\n')
            {
                while(ft_isdigit(line[i]) == 0)
                    i++;
                start = i;
                while(ft_isdigit(line[i]) == 1)
                    i++;
                end = i;
                number = ft_substr(line,start,end-start);
                numberato = ft_atoi(number);
                call_map->ceiling_color[j] = numberato;
                j++;
            }
        }
        else if(ft_strchr(line,'1'))
        {
            while(line)
            {
                call_map->map = ft_strjoin(call_map->map,line);
                line = get_next_line(fd);
            }
        }
        line = get_next_line(fd);
    }
    close(fd);
}