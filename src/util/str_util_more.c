/*
** str_util_more.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar  8 10:25:12 2017 romain pillot
** Last update Wed Mar  8 21:05:21 2017 romain pillot
*/

#include <stdbool.h>
#include "util.h"
#include <stdlib.h>

bool	start_withstr(char *str, char *charset)
{
  if (!str || !charset)
    return (false);
  while (*charset)
    if (*str++ != *charset++)
      return (false);
  return (true);
}

char	*strdupl(char *str)
{
  char	*new;
  char	*hold;

  hold = (new = malloc(sizeof(char) * (str_length(str) + 1)));
  while (*str)
    *new++ = *str++;
  *new = 0;
  return (hold);
}
