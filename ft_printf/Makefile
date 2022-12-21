NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

HEADERS = headers/libftprintf.h\

CC = gcc

SRC = ft_printf.c\
	functions/main_parser.c\
	functions/ft_atoi.c\
	processor/processor.c\
	functions/int_processor_d_i.c\
	functions/ft_write.c\
	functions/ft_putnbr_fd.c\
	functions/str_processor.c\
	functions/ft_strlen.c\
	functions/char_processor.c\
	functions/uint_processor.c\
	functions/ft_uint_putnbr_fd.c\
	functions/sixteen_processor.c\
	functions/ft_sxt_putnbr_fd.c\
	functions/ptr_processor.c\
	functions/percent_processor.c\
	functions/ft_ptr_putnbr_fd.c\
	functions/ft_ull_putnbr_fd.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): ${OBJ} ${HEADERS}
	ar rc ${NAME} ${OBJ} ${HEADERS}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all