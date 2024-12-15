/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irfei <irfei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:10:29 by irfei             #+#    #+#             */
/*   Updated: 2024/12/03 04:10:37 by irfei            ###   ########.fr       */
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
void    ft_bzero(void *s, size_t n);
size_t  ft_strlen(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strdup(const char *s1);
char    *get_next_line(int fd);

#endif // GET_NEXT_LINE_H