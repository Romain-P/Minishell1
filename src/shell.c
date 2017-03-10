/*
** shell.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 02:18:12 2017 romain pillot
** Last update Fri Mar 10 19:16:05 2017 romain pillot
*/

#include "minishell.h"
#include "util.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static bool	has_child;

static void	display_prompt()
{
  char		*sub;
  char		path[1024];

  sub = NULL;
  if (getcwd(path, 1024))
    {
      display(count_char(path, '/') > 2 ?
	      (sub = rev_substr(path, '/', 2)) : path);
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
  if (!has_child)
    display_prompt();
}

void	launch(t_shell *shell, int file)
{
  char	*cmd_line;
  char	**args;

  signal(SIGINT, &exit_handle);
  while (shell->status == -1)
    {
      has_child = false;
      if (shell->isatty)
	display_prompt();
      if (!(cmd_line = scan_line(file)))
	shell->exit(shell, EXIT_SUCCESS, shell->isatty ? "exit\n" : NULL);
      else
	{
	  has_child = true;
	  args = splitstr(cmd_line, ' ');
	  if (args && *args)
	    shell->cmds[get_cmd_index(*args)](shell, args);
	  free(args);
	  free(cmd_line);
	}
    }
}
