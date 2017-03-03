/*
** shell.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 02:18:12 2017 romain pillot
** Last update Fri Mar  3 07:53:42 2017 romain pillot
*/

#include "minishell.h"
#include "util.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void	display_prompt()
{
  char		*sub;
  char		path[1024];

  sub = NULL;
  if (getcwd(path, 1024))
    {
      display(count_char(path, '/') > 2 ?
	      (sub = rev_substring(path, '/', 2)) : path);
      display("> ");
      if (sub)
	free(sub);
    }
  else
    perror("getcwd");
}

static void     exit_handle()
{
  display_char('\n');
  display_prompt();
}

static void	execute(t_shell *shell)
{
  display("executed: ");
  display(shell->cmd);
  display_char('\n');
}

void	launch(t_shell *shell)
{
  char	path[1024];
  int	file;
  bool	isatty;

  signal(SIGINT, &exit_handle);
  isatty = shell->isatty;
  while (shell->status == -1)
    {
      if (isatty)
	display_prompt();
      if (!(shell->cmd = scan_line(shell->file, shell)))
	shell->exit(shell, EXIT_SUCCESS, isatty ? "exit\n" : NULL);
      else
	{
	  execute(shell);
	  free(shell->cmd);
	}
    }
}
