/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eisikogl <eisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:19:54 by calion            #+#    #+#             */
/*   Updated: 2022/12/20 23:51:37 by eisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	parse_floor(t_gamedata *call_map, char *line, int i)
{
	int		j;
	int		start;
	int		end;
	int		numberato;
	char	*number;

	j = 0;
	i = 0;
	while (line[i] != '\n')
	{
		while (ft_isdigit(line[i]) == 0)
			i++;
		start = i;
		while (ft_isdigit(line[i]) == 1)
			i++;
		end = i;
		number = ft_substr(line, start, end - start);
		numberato = ft_atoi(number);
		free(number);
		call_map->floor_color[j] = numberato;
		j++;
	}
}

void	parse_ceiling(t_gamedata *call_map, char *line,int i)
{
	int		j;
	int		start;
	int		end;
	char	*number;
	int		numberato;

	j = 0;
	i = 0;
	while (line[i] != '\n')
	{
		while (ft_isdigit(line[i]) == 0)
			i++;
		start = i;
		while (ft_isdigit(line[i]) == 1)
			i++;
		end = i;
		number = ft_substr(line, start, end - start);
		numberato = ft_atoi(number);
		free(number);
		call_map->ceiling_color[j] = numberato;
		j++;
	}
}

void	read_map(t_gamedata *call_map)
{
	int		fd;
	int		i;
	char	*line;
	char	*parsed_line;

	fd = open(call_map->map_path, O_RDONLY);
	line = get_next_line(fd);
	call_map->floor_color = malloc(sizeof(int) * 3);
	call_map->ceiling_color = malloc(sizeof(int) * 3);
	while (line)
	{
		if (!ft_strncmp(line, "NO", 2))
		{
			parsed_line = ft_strchr(line, '.');
			call_map->north_texture_path = parsed_line;
		}
		else if (!ft_strncmp(line, "SO", 2))
		{
			parsed_line = ft_strchr(line, '.');
			call_map->south_texture_path = parsed_line;
		}
		else if (!ft_strncmp(line, "WE", 2))
		{
			parsed_line = ft_strchr(line, '.');
			call_map->west_texture_path = parsed_line;
		}
		else if (!ft_strncmp(line, "EA", 2))
		{
			parsed_line = ft_strchr(line, '.');
			call_map->east_texture_path = parsed_line;
		}
		else if (!ft_strncmp(line, "F", 1))
		{
			parse_floor(call_map, line, i);
		}
		else if (!ft_strncmp(line, "C", 1))
		{
			parse_ceiling(call_map, line, i);
		}
		else if (ft_strchr(line, '1'))
		{
			while (line)
			{
				call_map->map = ft_strjoin(call_map->map, line);
			//	free(line);
				line = get_next_line(fd);
			}
		}
		line = get_next_line(fd);
	}
	//free(line);
	close(fd);
}

int	get_line_len(t_gamedata *call_map)
{
	int	i;
	int	temp;
	int	j;

	i = 0;
	temp = 0;
	while (call_map->map_split[i] != NULL)
	{
		j = 0;
		while (call_map->map_split[i][j] != '\0')
		{
			j++;
		}
		if (j > temp)
		{
			temp = j;
		}
		i++;
	}
	return (temp);
}

int	get_height(t_gamedata *call_map)
{
	int	i;

	i = 0;
	while (call_map->map_split[i] != NULL)
	{
		i++;
	}
	return (i);
}