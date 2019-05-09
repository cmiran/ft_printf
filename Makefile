# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 11:43:16 by cmiran            #+#    #+#              #
#    Updated: 2019/05/09 18:11:04 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

CC= gcc
CFLAGS= -Wall -Wextra -Werror

SRC= ft_printf.c\
	conversions.c\
	numbers.c\
	binarys.c\
	floats.c\
	strings.c

LIB_DIR= ./lib/
LIB= ft_isdigit.c\
	ft_isupper.c\
	ft_strlen.c\
	pf_putchar.c\
	pf_atoi.c\
	pf_getbase.c\
	pf_nbrlen.c\
	pf_unbrlen.c\
	pf_putnbr.c\
	pf_putnbr_base.c\
	pf_putnchar.c\
	pf_putnstr.c\
	pf_strchr.c

INC= $(addprefix -I , .)

OBJ_DIR= .obj/
OBJ= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))\
	$(addprefix $(OBJ_DIR), $(LIB:.c=.o))


all: $(NAME)

$(NAME): $(OBJ)# $(OBJLIB)
	@echo "\033[0;35m    Creating library...\033[0m"
	@ar rc $@ $(OBJ) $(OBJLIB)
	@echo "\033[0;36m  Indexing library...\033[0m"
	@ranlib $@
	@ls | grep libftprintf.a

$(OBJ_DIR)%.o: %.c 
	@mkdir -p $(OBJ_DIR)
	@echo "\033[0;33m      Compiling\033[0m		"$<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(OBJ_DIR)%.o: $(LIB_DIR)%.c 
	@mkdir -p $(OBJ_DIR)
	@echo "\033[0;33m      Compiling\033[0m		"$<
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	@echo "\033[0;31mDeleting dependencies\033[0m	"$(OBJ_DIR)
	@echo "\033[0;31mDeleting dependencies\033[0m	"$(OBJLIB_DIR)
	@rm -f $(OBJ) $(OBJLIB)
	@rm -rf $(OBJ_DIR) $(OBJLIB_DIR)

fclean: clean
	@echo "\033[0;31mDeleting library\033[0m	"$(NAME)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
