# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouchla <ibouchla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 12:21:30 by ibouchla          #+#    #+#              #
#    Updated: 2016/02/03 23:32:44 by ibouchla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

INC_PATH = -I includes

SRC_PATH = src

SRC_NAME =	test.c \
			main.c

CC_FLAGS = clang -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJET = $(SRC:.c=.o)

LD_PATH = -L libft

LD_LIB = -lft

RED = \033[1;31m

BLUE = \033[1;34m

GREEN = \033[0;32m

YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJET)
	@echo "$(BLUE)Compilation of object files is complete.\n"
	@echo "$(YELLOW)Compilation of the library in progress.."
	@make -C libft/ re > /dev/null
	@echo "$(BLUE)Compilation is complete.\n"
	@echo "$(YELLOW)Linkage in progress.."
	@$(CC_FLAGS) $(OBJET) $(LD_PATH) $(LD_LIB) -o $(NAME) > /dev/null
	@echo "$(BLUE)Linkage is complete.\n"
	@make -C libft/ fclean > /dev/null
	@echo "$(RED)Deleting of object files in libft directory"
	@echo "$(RED)Remove the library\n"
	@echo "$(GREEN)Done."

%.o: %.c
	@$(CC_FLAGS) -c $< $(INC_PATH) -o $@ > /dev/null
	@echo "\033[1;32mCompilation of object file : $(GREEN)Success"
clean:
	@echo "\n$(RED)Deleting of object files"
	@$(RM) $(OBJET) > /dev/null

fclean: clean
	@echo "$(RED)Remove the executable\n"
	@$(RM) $(NAME) > /dev/null

re: fclean all
