/* ********************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irfei <irfei@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:10:29 by irfei             #+#    #+#             */
/*   Updated: 2025/01/07 20:39:47 by irfei            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*get_next_line(int fd);

#endif