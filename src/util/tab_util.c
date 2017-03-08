/*
** tab_util.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar  8 13:58:37 2017 romain pillot
** Last update Wed Mar  8 14:19:51 2017 romain pillot
*/

#include "util.h"
#include <stdlib.h>

int	tab_length(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i] && i++);
  return (i);
}

char	*tab_start_withstr(char **tab, char *charset)
{
  char	*str;

  while ((str = *tab++))
    if (start_withstr(str, charset))
      return (str);
  return (NULL);
}
