##
## makefile for make in /home/jordan.roucom/CPool_rush3
## 
## Made by Jordan Rouco miguez
## Login   <jordan.roucom@epitech.net>
## 
## Started on  Sat Oct 29 17:09:21 2016 romain pillot
## Last update Mon Mar  6 03:15:01 2017 romain pillot
##

CC	=	gcc

NAME	=	mysh

RM	=	rm -f

SRCS	=	src/main.c		\
		src/shell.c		\
		src/command.c		\
		src/util/display.c	\
		src/util/scanner.c	\
		src/util/str_util.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-Iinclude #-Werror -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
