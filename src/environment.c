/*
** environment.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Wed Mar  8 11:44:53 2017 romain pillot
** Last update Wed Mar  8 14:24:56 2017 romain pillot
*/

char	**get_paths(char **env)
{
  char	*str;

  while ((str = *env++))
    if (start_withstr(str, "PATH"))
      return (splitstr(str + 5, ':'));
  return (NULL);
}

char	**copy_env(char **env, char **replace)
{
  char	**new;
  char	*str;

  new = malloc(sizeof(char *) * (tab_length(env) + 1));
  while ((str = *env))
    {
      
    }
}
