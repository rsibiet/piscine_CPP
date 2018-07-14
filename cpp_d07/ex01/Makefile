# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 10:10:33 by rsibiet           #+#    #+#              #
#    Updated: 2017/06/07 10:10:35 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter

FTC = iter.cpp

FTO = $(FTC:%.cpp=%.o)

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@echo "\033[32m• $(NAME) created!\n\033[0m"
	@clang++ -Wall -Wextra -Werror -o $(NAME) $(FTO)

%.o: %.cpp
	@clang++ -Wall -Wextra -Werror -o $@ -c $<

clean:
	@rm -rf $(FTO)
	@echo "\033[33m• $(NAME) object deleted!\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31;1m• \033[31m$(NAME) deleted!\033[0m"

re: fclean all
