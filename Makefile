# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 11:43:16 by cmiran            #+#    #+#              #
#    Updated: 2019/05/05 16:02:55 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

CC= gcc -g
CFLAGS= -Wall -Wextra -Werror

SRC_DIR= ./src/
SRC_NAME= ft_printf.c\
	conversions.c\
	numbers.c\
	binarys.c\
	floats.c\
	strings.c

LIB_DIR= ./lib/
LIB_NAME= ft_isdigit.c\
	ft_isupper.c\
	ft_nbrlen.c\
	pf_putchar.c\
	ft_strlen.c\
	get_base.c\
	pf_atoi.c\
	pf_nbrlen.c\
	pf_unbrlen.c\
	pf_putnbr.c\
	pf_putnbr_base.c\
	pf_putnchar.c\
	pf_putnstr.c\
	pf_strchr.c

INC_DIR= ./inc/
INC= $(addprefix -I , $(INC_DIR))

OBJ_DIR= ./.sources/
OBJ= $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))
OBJLIB_DIR= ./.library/
OBJLIB= $(addprefix $(OBJLIB_DIR), $(LIB_NAME:.c=.o))


all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@echo "\033[0;35m    Creating library...\033[0m"
	@ar rc $@ $(OBJ) $(OBJLIB)
	@echo "\033[0;36m  Indexing library...\033[0m"
	@ranlib $@
	@ls | grep libftprintf.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "\033[0;33m      Compiling:\033[0m" $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(OBJLIB_DIR)%.o: $(LIB_DIR)%.c
	@mkdir -p $(OBJLIB_DIR)
	@echo "\033[0;33m      Compiling:\033[0m" $<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	@echo "\033[0;31m    Deleting dependencies...\033[0m"	
	@rm -f $(OBJ) $(OBJLIB)
	@rm -rf $(OBJ_DIR) $(OBJLIB_DIR)

fclean: clean
	@echo "\033[0;31m  Deleting library...\033[0m"	
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
