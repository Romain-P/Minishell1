/*
** command.h for  in /home/romain.pillot/projects/PSU_2016_minishell1/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 17:38:01 2017 romain pillot
** Last update Mon Mar  6 04:33:26 2017 romain pillot
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# include "minishell.h"

struct				s_shell;

typedef struct			s_linked_command
{
  char				*path;
  char				**args;
  void				(*execute)(char *path, char **args, struct s_shell *shell);
  struct s_linked_command	*next;
  struct s_linked_command	*prev;
}				t_linked_command;

t_linked_command		*create_command(char *path,
				       char **args,
				       void (*execute)(char *path, char **args, struct s_shell *shell));

void				add_command(struct s_shell *shell, t_linked_command *new);

t_linked_command		*find_command(struct s_shell *shell, char *name);

#endif /* !COMMAND_H_ */
