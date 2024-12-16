/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irfei <irfei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:46:30 by irfei             #+#    #+#             */
/*   Updated: 2024/12/16 21:59:21 by irfei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *get_next_line(int fd)
{
	static char	*remainder;
	char		*buf;
	char		*line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!remainder)
		return (NULL);
	line = ft_strchr(remainder, '\n');
}
char *read_and_store(int ft, char *buffer, char *remainder)
{
	ssize_t bytes_read;
	char *temp;
	buffer = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!remainder)
	{
		remainder = (char *)malloc(1);
		if (!remainder)
		{
			free(buffer);
			return (NULL);
		}
		remainder[0] = '\0';
	}
	
	
}
	
	