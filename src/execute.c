/*
** execute.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Mar  9 14:13:51 2017 romain pillot
** Last update Fri Mar 10 02:01:55 2017 romain pillot
*/

#include "environment.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "minishell.h"
#include "util.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

static void	execute(t_shell *shell, char *path, char **args)
{
  pid_t		pid;
  int		wstatus;

  if ((pid = fork()) == -1)
    perror("fork");
  else if (pid == CHILD_PROCESS && execve(path, args, shell->env) == -1)
    perror("execve");
  else
    while (waitpid(pid, &wstatus, 0) != -1 &&
	   !WIFEXITED(wstatus));
}

static int	try_exec_access(char *path, char **denied)
{
  struct stat	rights;
  int		right;

  if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
    if (!stat(path, &rights) && rights.st_mode & S_IXUSR)
      right = ACCESS;
    else
      {
        safe_free(*denied);
	*denied = path;
	right = DENIED;
      }
  else
    right = NOT_FOUND;
  if (right == NOT_FOUND)
    safe_free(path);
  return (right);
}

void            search_cmd(t_shell *shell, char **args)
{
  char          **paths;
  char          **hold;
  char          *str;
  char		*denied;
  int		right;

  paths = (hold = get_paths(shell->env));
  denied = NULL;
  while ((str = *paths++))
    {
      str = concatstr(str, "/", false);
      str = concatstr(str, *args, true);
      if ((right = try_exec_access(str, &denied)) == ACCESS)
	{
	  execute(shell, str, args);
	  free(str);
	  break;
	}
    }
  display(right == ACCESS ? NULL : denied ? denied : args[0]);
  display(right == ACCESS ? NULL : denied ? DENIED_STR : NFOUND_STR);
  safe_free(denied);
  safe_freesub(hold, true);
}