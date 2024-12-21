/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irfei <irfei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 06:29:04 by irfei             #+#    #+#             */
/*   Updated: 2024/12/21 07:15:28 by irfei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_load_buffer(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	if (!stash)
		stash = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(stash), stash = NULL, NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), buffer = NULL, free(stash), stash = NULL,
				NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (free(buffer), buffer = NULL, NULL);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (free(buffer), buffer = NULL, stash);
}

char	*ft_extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), stash = NULL, NULL);
	i++;
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (free(stash), stash = NULL, NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	return (free(stash), stash = NULL, new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = ft_load_buffer(fd, stash[fd]);
	if (!stash[fd])
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = ft_extract_line(stash[fd]);
	if (!line)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	stash[fd] = ft_clean_stash(stash[fd]);
	return (line);
}
int main(void) {
    int fd1 = open("file1.txt", O_RDWR);
    int fd2 = open("file2.txt", O_RDONLY);
    int fd3 = open("file3.txt", O_RDONLY);

    char *line1, *line2, *line3;
    while ((line2 = get_next_line(fd2)) || 
           (line1 = get_next_line(fd1)) || 
           (line3 = get_next_line(fd3))) {
        if (line2) {
            printf("File 2: %s", line1);
            free(line2);
        }
        if (line1) {
            printf("File 1: %s", line2);
            free(line1);
        }
        if (line3) {
            printf("File 3: %s", line3);
            free(line3);
        }
    }

	close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}
