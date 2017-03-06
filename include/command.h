/*
** command.h for  in /home/romain.pillot/projects/PSU_2016_minishell1/include
** 
** Made by romain pillot
** Login   <romain.pillot@epitech.net>
** 
** Started on  Fri Mar  3 17:38:01 2017 romain pillot
** Last update Fri Mar  3 19:02:31 2017 romain pillot
*/

#ifndef COMMAND_H_
# define COMMAND_H_

typedef struct	s_command
{
  char		*name;
  char		**args;
  void		(*execute)(char **args);
}		t_command;

#endif /* !COMMAND_H_ */
