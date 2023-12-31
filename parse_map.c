/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:50:12 by chorse            #+#    #+#             */
/*   Updated: 2022/11/04 20:43:45 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	*ft_realloc(void *buf, int before, int after)
{
	int		i;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after);
	i = 0;
	while (i < before)
	{
		dst[i] = src[i];
		i++;
	}
	free(buf);
	return ((void *)dst);
}

void	map_info(t_map *info, int fd)
{
	char	*line;

	line = trim_line(new_line(fd), 1);
	if (!line)
		throw_error("Error\nEmpty file");
	while (*line == '\0')
	{
		free(line);
		line = trim_line(new_line(fd), 1);
	}
	while (line)
	{
		info->map = (char **)ft_realloc(info->map, info->h, info->h + 1);
		info->map[info->h] = line;
		info->h++;
		if (info->w < ft_strlen(line))
			info->w = ft_strlen(line);
		line = trim_line(new_line(fd), 1);
	}
	if (line)
		free(line);
	close(fd);
}
