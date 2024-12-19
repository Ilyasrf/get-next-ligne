/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irfei <irfei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:46:30 by irfei             #+#    #+#             */
/*   Updated: 2024/12/19 04:36:33 by irfei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_fill_buffer(int fd, char *stash)
{
    char *buffer;
    ssize_t bytes_read;

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
            return (free(buffer), buffer = NULL, free(stash), stash = NULL, NULL);
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (!stash)
            return (free(buffer), buffer = NULL, NULL);
        if (ft_strchr(stash, '\n'))
            break;
    }
    return (free(buffer), buffer = NULL, stash);
}

char *ft_extract_line(char *stash)
{
    int i = 0;
    char *line;

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

char *ft_trim_stash(char *stash)
{
    char *new_stash;
    int i = 0, j = 0;

    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
        return (free(stash), stash = NULL, NULL);
    i++;
    new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
    if (!new_stash)
        return (free(stash), stash = NULL, NULL);
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    return (free(stash), stash = NULL, new_stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
        return (free(stash), stash = NULL, NULL);
    stash = ft_fill_buffer(fd, stash);
    if (!stash)
        return (free(stash), stash = NULL, NULL);
    line = ft_extract_line(stash);
    if (!line)
        return (free(stash), stash = NULL, NULL);
    stash = ft_trim_stash(stash);
    return (line);
}
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) // Read each line until EOF
    {
        printf("%s", line); // Print the line
        free(line);         // Free the memory allocated for the line
    }

    if (close(fd) < 0) // Close the file descriptor
    {
        perror("Error closing file");
        return 1;
    }

    return 0;
}