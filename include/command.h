/*
** command.h for  in /home/romain.pillot/projects/PSU_2016_minishell1/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 17:38:01 2017 romain pillot
** Last update Mon Mar  6 02:45:53 2017 romain pillot
*/

#ifndef COMMAND_H_
# define COMMAND_H_

typedef struct	s_command
{
  char		*path;
  char		**args;
  void		(*execute)(char *path, char **args);
}		t_command;

#endif /* !COMMAND_H_ */
