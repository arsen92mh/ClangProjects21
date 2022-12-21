NAME = cub3D

SRC = get_next_line.c \
	parser/parser.c parser/screen_resolution.c \
	error_mgnmnt/error_manager.c \
	parser/config_manage.c validator/validator.c \
	ft_cub_start.c validator/arg_validator.c \
	ft_initialiser_1.c ft_initialiser_2.c ft_initialiser_3.c \
	validator/validator_utils.c \
	ft_scrshot.c ft_sprites.c ft_fix_resolution.c \
	ft_casting.c ft_spr_cast.c ft_mlx_pix_put.c \
	ft_casting_utils.c ft_spr_cast_calc.c ft_shift.c \
	parser/ft_floor_ceiling.c parser/ft_scr_res_utils.c \
	parser/ft_num.c

FLAGS = gcc -Wextra -Wall -Werror

OBJ = $(SRC:.c=.o)

H = cub3d.h

all: $(NAME)

$(NAME): Libft/libft.a cub3d.a
	$(FLAGS) main.c Libft/libft.a cub3d.a -framework OpenGL -framework AppKit libmlx.dylib -o $(NAME)

cub3d.a: $(OBJ)
	ar rc cub3d.a $?
	ranlib cub3d.a

%.o:%.c
	$(FLAGS) -c $< -o $@

Libft/libft.a:
	$(MAKE) -C ./Libft

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./Libft

fclean: clean
	rm -f $(NAME) cub3d.a
	$(MAKE) fclean -C ./Libft

re: fclean all

bonus: re