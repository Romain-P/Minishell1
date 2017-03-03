/*
** main.h for  in /home/romain.pillot/bin
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Thu Nov 24 11:15:51 2016 romain pillot
** Last update Fri Mar  3 06:51:36 2017 romain pillot
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

# include "stdbool.h"

typedef struct	s_shell
{
  bool		isatty;
  char		*cmd;
  int		file;
  char		**env;
  int		status;
  void		(*exit)(struct s_shell *shell, int status, char *message);
}		t_shell;

void		launch(t_shell *shell);

#endif /** !MINISHELL_H_ **/
