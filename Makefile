# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bben-aou <bben-aou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 17:37:27 by bben-aou          #+#    #+#              #
#    Updated: 2022/04/13 22:41:05 by bben-aou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNS  = so_long_bonus

CFLAGS = -Wall -Wextra -Werror -Imlx

src = so_long.c \
	  utils.c \
	  get_next_line.c \
	  get_next_line_utils.c \
	  check_map.c \
	  get_and_set.c \
	  moves.c \
	  print_map.c \
	  utils_map.c \
	  ft_split.c \
	  messages.c \
	  reprint_map.c \
	  
src_b = ./bonus/check_map_bonus.c \
		./bonus/get_and_set_bonus.c \
		./bonus/moves_bonus.c \
		./bonus/printf_map_bonus.c \
		./bonus/so_long_bonus.c \
		./bonus/utils_bonus.c \
		./bonus/utils_map_bonus.c \
		./get_next_line.c \
		./get_next_line_utils.c \
		./bonus/ft_itoa.c \
		./ft_split.c \
		./bonus/moves_case_bonus.c \
		./bonus/reprint_map_bonus.c \
		./bonus/moves_enemy.c \
		./bonus/messages_bonus.c \
		./bonus/messages_files_bonus.c \
		

HDRS = ./so_long.h \
	   ./bonus/so_long_bonus.h \
	   ./get_next_line.h \

ft_printf = ./ft_printf/libftprintf.a
OBJ = $(src:.c=.o)
OBJB = $(src_b:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@make -sC ft_printf
	@gcc $(CFLAGS) $^ $(ft_printf) -lmlx -framework OpenGL -framework AppKit -o $@
	@echo "\033[1;32m##########COMPILED SUCCESSFULY##########\033[0m"

bonus : $(OBJB)
	@make -sC ft_printf
	@gcc $(CFLAGS) $(OBJB) $(ft_printf) -lmlx -framework OpenGL -framework AppKit -o $(BNS)
	@echo "\033[1;32m##########BONUS COMPILED SUCCESSFULY##########\033[0m"

%.o: %.c $(HDRS)
	@gcc $(CFLAGS) -c $< -o $@ 

clean:
	@make  -sC ft_printf clean
	@rm -f $(OBJ)
	@rm -f $(OBJB)

fclean: clean
	@make  -sC ft_printf fclean
	@rm -f $(NAME)
	@rm -f $(BNS)
	@echo "\033[1;32m##########CLEANED SUCCESSFULY##########\033[0m"

re: fclean all
