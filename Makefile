# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmiran <cmiran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 11:43:16 by cmiran            #+#    #+#              #
#    Updated: 2019/03/30 14:26:42 by cmiran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprinft.a

CC= gcc -g
CFLAGS= -Wall -Wextra -Werror

SRC_DIR= ./src/
SRC_NAME= ft_printf.c\
	numbers.c
SRC= $(addprefix $(SRC_DIR), $(SRC_NAME))

LIB_DIR= ./lib/

LIB_NAME= ft_atoi.c\
	ft_bzero.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_isspace.c\
	ft_isupper.c\
	ft_nbrlen.c\
	ft_unbrlen.c\
	ft_print_memory.c\
	ft_putchar.c\
	ft_putnbr.c\
	ft_putnchar.c\
	ft_strlen.c\
	pf_atoi.c\
	pf_itoc.c\
	pf_putnbr.c\
	pf_putnbr_base.c\
	pf_strchr.c

LIB= $(addprefix $(LIB_DIR), $(LIB_NAME))

INC_DIR= ./inc/
INC= $(addprefix -I , $(INC_DIR))

OBJ_DIR= ./obj/
OBJ= $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))
OBJLIB_DIR= ./objlib/
OBJLIB= $(addprefix $(OBJLIB_DIR), $(LIB_NAME:.c=.o))


all: $(NAME)

$(NAME): obj $(OBJ) $(OBJLIB)
	ar rc $@ $(OBJ) $(OBJLIB)
	ranlib $@

obj:
	mkdir -p ./obj/
	mkdir -p ./objlib/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(OBJLIB_DIR)%.o: $(LIB_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	rm -f $(OBJ) $(OBJLIB)
	rm -rf $(OBJ_DIR) $(OBJLIB_DIR)

fclean: clean
	rm -f $(NAME)

#lldb :
#	$(CC) $(CFLAGS) $(INC) $(SRC) $(LIB) -o $(NAME)

re: fclean all

.PHONY: all clean fclean re
