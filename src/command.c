/*
** command.c for  in /home/romain.pillot/projects/PSU_2016_minishell1/src
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Mon Mar  6 03:14:45 2017 romain pillot
** Last update Mon Mar  6 04:31:21 2017 romain pillot
*/

#include "minishell.h"
#include "util.h"
#include <stdlib.h>

t_linked_command	*create_command(char *path,
				       char **args,
				       void (*execute)(char *path, char **args, t_shell *shell))
{
  t_linked_command	*command;

  command = malloc(sizeof(t_linked_command));
  command->path = path;
  command->args = args;
  command->execute = execute;
  return (command);
}

void	add_command(t_shell *shell, t_linked_command *new)
{
  new->next = shell->commands;
  shell->commands->prev = new;
  shell->commands = new;
}

t_linked_command	*find_command(t_shell *shell, char *name)
{
  t_linked_command	*cmd;

  cmd = shell->commands;
  while (cmd)
    {
      if (equalstr(cmd->args[0], name))
	{
	  if (cmd->prev)
	    {
	      cmd->prev->next = cmd->next;
	      if (cmd->next)
		cmd->next->prev = cmd->prev;
	      cmd->next = shell->commands;
	      shell->commands->prev = cmd;
	      shell->commands = cmd;
	    }
	  return (cmd);
	}
      cmd = cmd->next;
    }
  return (NULL);
}
