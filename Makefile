##
## makefile for make in /home/jordan.roucom/CPool_rush3
## 
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
## 
## Started on  Sat Oct 29 17:09:21 2016 romain pillot
## Last update Wed Mar 22 14:47:42 2017 romain pillot
##

CC	=	gcc

NAME	=	mysh

RM	=	rm -f

SRCS	=	src/main.c			\
		src/shell.c			\
		src/environment.c		\
		src/execute.c			\
		src/built-in/cd.c		\
		src/built-in/env.c		\
		src/built-in/setenv.c		\
		src/built-in/unsetenv.c		\
		src/built-in/exit.c		\
		src/util/display.c		\
		src/util/scanner.c		\
		src/util/tab_util.c		\
		src/util/str_util.c		\
		src/util/str_util_more.c	\
		src/util/util.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinclude -g #-Werror -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
