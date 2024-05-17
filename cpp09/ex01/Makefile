# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 11:23:35 by vcereced          #+#    #+#              #
#    Updated: 2024/03/20 13:01:44 by vcereced         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = rpn

SRC = main.cpp Rpn.cpp
 
FLAGS = #-Wall -Werror -Wextra -std=c++98

CC = c++

OBJDIR = ./obj

OBJS = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):  $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

exe: all
	./$(NAME) "123456789"

.PHONY: all clean fclean re