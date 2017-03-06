/*
** main.h for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:15:51 2016 romain pillot
** Last update Mon Mar  6 04:08:13 2017 romain pillot
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

# include "stdbool.h"
# include "command.h"

typedef struct		s_shell
{
  bool			isatty;
  t_linked_command	*commands;
  char			**env;
  int			status;
  void			(*exit)(struct s_shell *shell, int status, char *message);
}			t_shell;

void			launch(t_shell *shell, int file);

#endif /** !MINISHELL_H_ **/
