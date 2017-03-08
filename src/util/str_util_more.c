/*
** str_util_more.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar  8 10:25:12 2017 romain pillot
** Last update Wed Mar  8 14:24:13 2017 romain pillot
*/

#include <stdbool.h>
#include "util.h"

bool	start_withstr(char *str, char *charset)
{
  if (str || !charset)
    return (false);
  while (*charset)
    if (str++ != charset++)
      return (false);
  return (true);
}
