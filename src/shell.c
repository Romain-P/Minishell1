/*
** shell.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 02:18:12 2017 romain pillot
** Last update Wed Mar 22 17:01:30 2017 romain pillot
*/

#include "minishell.h"
#include "util.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "builtin.h"

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

static void	apply_command(t_shell *shell, char *cmd_line)
{
  char		**args;
  char		*tofree;
  static void   (* const cmds[6]) (struct s_shell *shell, char **args) =
    {
      &cd_alt, &setenv_alt, &unsetenv_alt, &env_alt, &exit_alt, &search_cmd
    };
  
  args = splitstr(strdupl(cmd_line), ' ');
  if (args && *args)
    cmds[get_cmd_index(*args)](shell, args);
  free(*args);
  free(args);
}

void		launch(t_shell *shell, int file)
{
  char		*cmds_line;
  char		**cmds;
  int		i;

  signal(SIGINT, &exit_handle);
  while (shell->status == -1)
    {
      has_child = false;
      if (shell->isatty)
	display_prompt();
      if (!(cmds_line = scan_line(file)))
	shell->exit(shell, EXIT_SUCCESS, shell->isatty ? "exit\n" : NULL);
      else
	{
	  has_child = true;
	  cmds = splitstr(cmds_line, ';');
	  i = -1;
	  while (cmds[++i])
	    apply_command(shell, cmds[i]);
	  free(cmds);
	  free(cmds_line);
	}
    }
}

int     get_cmd_index(char *str)
{
  return (equalstr(str, "cd") ? CD :
	  equalstr(str, "setenv") ? SETENV :
	  equalstr(str, "unsetenv") ? UNSETENV :
	  equalstr(str, "env") ? ENV :
	  equalstr(str, "exit") ? EXIT : SEARCH_CMD);
}
