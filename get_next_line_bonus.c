/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irfei <irfei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:29:04 by irfei             #+#    #+#             */
/*   Updated: 2024/12/17 06:40:02 by irfei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_file(int fd, char *dumpstr)
{
	int		bytes_read;
	char	*buffer;

	if (!dumpstr)
		dumpstr = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(dumpstr), dumpstr = NULL, NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), buffer = NULL, free(dumpstr), dumpstr = NULL,
				NULL);
		buffer[bytes_read] = '\0';
		dumpstr = ft_strjoin(dumpstr, buffer);
		if (!dumpstr)
			return (free(buffer), buffer = NULL, NULL);
		if (ft_strchr(dumpstr, '\n'))
			break ;
	}
	return (free(buffer), buffer = NULL, dumpstr);
}

char	*ft_get_line(char *dumpstr)
{
	char	*line;
	int		i;

	i = 0;
	if (!dumpstr || !dumpstr[0])
		return (NULL);
	while (dumpstr[i] && dumpstr[i] != '\n')
		i++;
	if (dumpstr[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (dumpstr[i] && dumpstr[i] != '\n')
	{
		line[i] = dumpstr[i];
		i++;
	}
	if (dumpstr[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_recycle_dumpstr(char *dumpstr)
{
	char	*new_dumpstr;
	int		i;
	int		j;

	i = 0;
	while (dumpstr[i] && dumpstr[i] != '\n')
		i++;
	if (!dumpstr[i])
		return (free(dumpstr), dumpstr = NULL, NULL);
	i++;
	new_dumpstr = malloc(sizeof(char) * (ft_strlen(dumpstr) - i + 1));
	if (!new_dumpstr)
		return (free(dumpstr), dumpstr = NULL, NULL);
	j = 0;
	while (dumpstr[i])
		new_dumpstr[j++] = dumpstr[i++];
	new_dumpstr[j] = '\0';
	return (free(dumpstr), dumpstr = NULL, new_dumpstr);
}

char	*get_next_line(int fd)
{
	static char	*dumpstr[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (free(dumpstr[fd]), dumpstr[fd] = NULL, NULL);
	dumpstr[fd] = ft_read_file(fd, dumpstr[fd]);
	if (!dumpstr[fd])
		return (free(dumpstr[fd]), dumpstr[fd] = NULL, NULL);
	line = ft_get_line(dumpstr[fd]);
	if (!line)
		return (free(dumpstr[fd]), dumpstr[fd] = NULL, NULL);
	dumpstr[fd] = ft_recycle_dumpstr(dumpstr[fd]);
	return (line);
}
