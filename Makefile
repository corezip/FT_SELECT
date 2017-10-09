NAME	= ft_ls

SRC		=	main.c print.c recursion.c sort.c flags.c helper.c time.c print_2.c bonus.c \
			sort2.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(OBJ) -o $(NAME) -L libft/ -lft
	@echo "\033[32mFT_LS: Built ft_ls. ~(˘▾˘~) \033[0m"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@echo "\033[32mFT_LS: Cleaned up object files. ~(˘▾˘~) \033[0m"

fclean: clean
	@$(MAKE) -C ./libft/ fclean
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)