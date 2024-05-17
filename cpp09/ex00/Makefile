# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 11:23:35 by vcereced          #+#    #+#              #
#    Updated: 2024/03/19 17:46:04 by vcereced         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = btc

SRC = main.cpp BitcoinExchange.cpp
 
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
	./$(NAME) input.txt

.PHONY: all clean fclean re