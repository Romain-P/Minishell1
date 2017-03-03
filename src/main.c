/*
** main.c for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:14:29 2016 romain pillot
** Last update Fri Mar  3 06:56:04 2017 romain pillot
*/

#include <stdlib.h>
#include <unistd.h>
#include "util.h"
#include <stdio.h>
#include <fcntl.h>

static void	exit_shell(t_shell *shell, int status, char *msg)
{
  if (msg)
    display(msg);
  shell->status = status;
}

static int	open_file(const char *file_name, t_shell *shell)
{
  int		file;

  if ((file = open(file_name, O_RDONLY)) == -1)
    {
      perror(file_name);
      shell->status = EXIT_FAILURE;
    }
  return (file);
}

int		main(int ac, char **args, char **env)
{
  t_shell	*shell;
  int		status;

  if (!(shell = malloc(sizeof(t_shell))))
    return (EXIT_FAILURE);
  shell->status = -1;
  shell->env = env;
  if ((shell->file = ac > 1 ? open_file(args[1], shell) : 0) != -1)
    {
      shell->isatty = isatty(shell->file);
      shell->exit = &exit_shell;
      launch(shell);
      if (ac > 1 && shell->status != EXIT_FAILURE)
	close(shell->file);
    }
  status = shell->status;
  free(shell);
  return (status);
}
