CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ./ft_printf.c ./ft_itoa.c ./print_specifiers_a.c\
		./print_hexa.c ./print_specifiers_b.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): make_mandatory

clean:
	rm -f $(OBJS)
	rm -f make_mandatory

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)
	rm -f make_mandatory

re: fclean all

make_mandatory: $(OBJS)
	ar rc $(NAME) $(OBJS)
	touch $@

.PHONY: all clean fclean re
