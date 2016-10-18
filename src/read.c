/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 13:53:28 by mbompoil          #+#    #+#             */
/*   Updated: 2016/10/18 18:18:42 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_process_buffer(char *buffer, t_map *map, int i, int to_data)
{
	char	**parsed_line;
	int		j;

	parsed_line = ft_strsplit(buffer, ' ');
	j = 0;
	while (parsed_line[j] != '\0')
	{
		if (to_data)
			map->tab[i][j] = ft_atoi(parsed_line[j]);
		free(parsed_line[j]);
		j++;
	}
	if (!to_data)
	{
		++map->nb_line;
		if (map->nb_column != j)
			map->nb_column = j;
	}
	free(parsed_line);
	free(buffer);
}

static void		ft_read_map(char *filename, t_map *map, int to_data)
{
	char	*buffer;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error("invalid filename");
	while (get_next_line(fd, &buffer) > 0)
		ft_process_buffer(buffer, map, i++, to_data);
	if (ft_strlen(buffer))
		ft_process_buffer(buffer, map, i++, to_data);
	close(fd);
}

static void		ft_malloc_map(t_map *map)
{
	int		i;

	map->tab = malloc(map->nb_line * sizeof(*map->tab));
	i = 0;
	while (i < map->nb_line)
		map->tab[i++] = malloc(map->nb_column * sizeof(**map->tab));
}

void			ft_parse(char *filename, t_wlf *wlf)
{
	wlf->map.nb_line = 0;
	wlf->map.nb_column = 0;
	ft_read_map(filename, &wlf->map, 0);
	ft_malloc_map(&wlf->map);
	ft_read_map(filename, &wlf->map, 1);
	if (wlf->map.nb_column <= 0 || wlf->map.nb_line <= 0)
		ft_error("map is too small");
}
