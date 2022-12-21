NAME = libasm.a

SRC	= 	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s  \
		ft_read.s   \
		ft_strdup.s \

OBJ	= $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o:%.s
	nasm -f macho64 -g $<

mf: $(NAME)
	gcc main.c $(NAME) -g -o test

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) test

re: fclean all