/*
** str_util.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src/util
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 04:26:23 2017 romain pillot
** Last update Mon Mar  6 03:21:32 2017 romain pillot
*/

#include <stdlib.h>
#include "util.h"

static int	len(char *str)
{
  int		i;

  i = 0;
  while (str && str[i] && ++i);
  return (i);
}

int	count_char(char *str, char c)
{
  int	i;
  int	j;

  i = (j = 0);
  while (str && str[i] && ++i)
    if (str[i] == c)
      j++;
  return (j);
}

char	*rev_substr(char *str,
		       const char c,
		       const int index)
{
  int	i;
  int	j;
  int	k;
  char	*nw;

  i = (j = len(str));
  k = 0;
  while (--i >= 0)
    if (str && str[i] == c && ++k == index && !(k = 0))
      break;
  if (!str || !(nw = malloc(sizeof(char) * (j - i))))
    return (NULL);
  while (str[++i])
    nw[k++] = str[i];
  nw[k] = 0;
  return (nw);
}

char    *trimstr(char *str)
{
  int   i;
  int   j;

  i = (j = 0);
  while(str && str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  if (i && j && (str[i - 1] == ' ' || str [i - 1] == '\t'))
	    str[j++] = ' ';
	  str[j++] = str[i++];
	}
      else
	i++;
    }
  if (str)
    str[j] = 0;
  return (str);
}

bool	equalstr(char *a, char *b)
{
  if (!a || !b)
    return (!a && !b);
  while (*a || *b)
    if (*a++ != *b++)
      return (false);
  return (true);
}
