# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dviegas <dviegas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 15:13:57 by dviegas           #+#    #+#              #
#    Updated: 2025/04/30 16:15:04 by dviegas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs

# Ficheiros do ft_printf
SRC = ft_printf.c ft_printf_utils.c ft_print_ptr.c ft_print_unsigned.c ft_print_hex.c ft_itoa.c
OBJ = $(SRC:.c=.o)




# Alvo principal
all: $(NAME)

# Cria a libftprintf.a combinando os objetos locais com a libft
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Compila objetos do ft_printf
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@



# Limpa os .o do ft_printf
clean:
	rm -f $(OBJ)

# Limpa tudo
fclean: clean
	rm -f $(NAME)


# Recompila tudo
re: fclean all

.PHONY: all clean fclean re