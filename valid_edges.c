/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_edges.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorse <chorse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:50:12 by chorse            #+#    #+#             */
/*   Updated: 2022/11/04 20:42:53 by chorse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	check_edge(char *line, int start, int last)
{
	if (line[last] != '1')
		throw_error("Error\nInvalid edges");
	if (line[start] != '1')
		throw_error("Error\nInvalid edges");
}

void	check_edges_parts(char *line, int start, int last)
{
	if (line[last] != '1')
		throw_error("Error\nInvalid edges");
	while (start < last)
	{
		if (line[start] != '1' && line[start] != ' ')
			throw_error("Error\nInvalid edges");
		start++;
	}
}

void	valid_edges(char *line, int height, int row)
{
	int	col;
	int	start;
	int	last;

	col = 0;
	start = ft_strchr(line, '1') - line;
	last = ft_strrchr(line, '1') - line;
	while (col < start)
	{
		if (line[col] != ' ')
			throw_error("Error\nInvalid edges");
		col++;
	}
	if (row == 0 || row == height - 1)
		check_edges_parts(line, start, last);
	else
		check_edge(line, start, last);
}
