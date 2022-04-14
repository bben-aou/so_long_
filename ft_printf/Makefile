NAME = libftprintf.a
AR = ar -rc
CC = gcc 
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar.c ft_putstr.c  ft_putnbr.c ft_putunsigned.c \
	   ft_hexaup.c ft_hexalow.c ft_check.c ft_check2.c ft_casep.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME) 
re : fclean all
