/*
** util.h for  in /home/romain.pillot/projects/PSU_2016_minishell1/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar  2 16:17:22 2017 romain pillot
** Last update Fri Mar  3 05:39:38 2017 romain pillot
*/

#ifndef UTIL_H_
# define UTIL_H_

# include "minishell.h"

char	*scan_line(const int fd, t_shell *shell);

void    display(char *str);

void    display_char(char c);

void    display_digit(int i);

int	count_char(char *str, char c);

char	*rev_substring(char *str, char c, int index);

#endif /* !UTIL_H_ */
