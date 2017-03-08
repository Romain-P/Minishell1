/*
** environment.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar  8 11:44:53 2017 romain pillot
** Last update Wed Mar  8 13:00:13 2017 romain pillot
*/

char	**get_paths(char **env)
{
  char	*str;

  while ((str = *env++))
    if (start_withstr(str, "PATH"))
      return (splitstr(str + 5, ':'));
  return (NULL);
}
