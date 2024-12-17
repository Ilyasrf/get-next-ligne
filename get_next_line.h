/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irfei <irfei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:10:29 by irfei             #+#    #+#             */
/*   Updated: 2024/12/17 05:50:03 by irfei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

// Define the buffer size
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

// Function prototypes

size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, char c);
char    *ft_strjoin(char *s1, char *s2);
char *ft_strdup(const char *s);

// Helper functions
int ft_count(char *buffer);
char *ft_read_file(int fd, char *buffer);
char *ft_get_line(char *buffer);
char *ft_update_buffer(char *buffer);
char *get_next_line(int fd);

#endif // GET_NEXT_LINE_H