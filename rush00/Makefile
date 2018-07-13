# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <rsibiet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 10:10:33 by rsibiet           #+#    #+#              #
#    Updated: 2017/06/17 18:44:54 by avella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

FTC = main.cpp \
	  Ft_retro.class.cpp \
	  Player.class.cpp \
	  Stone.class.cpp \
	  Shoot.class.cpp \
	  Enemy.class.cpp \
	  collisions.cpp \
	  Star.class.cpp \
	  BigStone.class.cpp \
	  BigBoss.class.cpp \
	  Entity.class.cpp

FTO = $(FTC:%.cpp=%.o)

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@echo "\033[32m• $(NAME) created!\n\033[0m"
	@clang++ -Wall -Wextra -Werror -lncurses -o $(NAME) $(FTO)

%.o: %.cpp
	@clang++ -Wall -Wextra -Werror -o $@ -c $<

clean:
	@rm -rf $(FTO)
	@echo "\033[33m• $(NAME) object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31;1m• \033[31m$(NAME) deleted!\033[0m"

re: fclean all
