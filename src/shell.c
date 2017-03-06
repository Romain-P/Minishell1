/*
** shell.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 02:18:12 2017 romain pillot
** Last update Mon Mar  6 02:44:23 2017 romain pillot
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

static void	parse(t_shell *shell, char *cmd_line)
{
  display("executed: ");
  display(cmd_line);
  display_char('\n');
}

void	launch(t_shell *shell, int file)
{
  char	*cmd_line;

  signal(SIGINT, &exit_handle);
  while (shell->status == -1)
    {
      if (shell->isatty)
	display_prompt();
      if (!(cmd_line = trim(scan_line(file))))
	shell->exit(shell, EXIT_SUCCESS, shell->isatty ? "exit\n" : NULL);
      else
	{
	  parse(shell, cmd_line);
	  free(cmd_line);
	}
    }
}
