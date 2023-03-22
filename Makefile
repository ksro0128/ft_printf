CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putadd.c ft_putchar.c ft_puthex.c ft_putnbr_fd.c ft_putrhex.c ft_putstr.c ft_putunbr.c ft_strlen.c take_format.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all
	
.PHONY : re clean fclean all