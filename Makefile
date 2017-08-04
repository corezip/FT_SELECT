NAME	= ft_select

SRC		=	main.c \
			helper.c \
			keys.c \
			print.c \
			size.c \
			t_var.c \
			termcpas.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(OBJ) -ltermcap -o $(NAME) -L libft/ -lft
	@echo "\033[32mft_select: Built ft_select. ~(˘▾˘~) \033[0m"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@echo "\033[32mft_select: Cleaned up object files. ~(˘▾˘~) \033[0m"

fclean: clean
	@$(MAKE) -C ./libft/ fclean
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)