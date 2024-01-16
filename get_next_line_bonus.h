/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrahimi <hbrahimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:37:31 by hbrahimi          #+#    #+#             */
/*   Updated: 2024/01/16 10:37:33 by hbrahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

char	*sub_str(char *s, unsigned int start, size_t len);
void	read_from_file(int fd, char **raw_material);
void	ft_clear(char **data);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*str_dup(char *str);
char	*concatenate(char *s1, char *s2);
int		find_nl(char *str);

#endif