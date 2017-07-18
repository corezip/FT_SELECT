# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsolis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 22:12:49 by gsolis            #+#    #+#              #
#    Updated: 2017/01/05 22:12:51 by gsolis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME = libft.a

# Compiling flags
FLAGS = -Wall -Wextra -Werror

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_nextword.c\
		ft_wordcount.c\
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstaddend.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_putwchar.c \
		ft_putwstr.c \
		ft_swap.c \
		ft_printf.c \
		helper.c \
		l_funtions.c \
		presition.c \
		print_p_m_u.c \
		print_s_d_o.c \
		s_presition.c \
		space.c \
		space_2.c \
		special.c \
		xnumber.c \
		zero.c \
		get_next_line.c \
		ft_lstaddback.c \
		ft_lstdeletenode.c \
		ft_printfcolor.c \
		ft_matrix.c \
		ft_delmat.c

OBJ = $(SRC:.c=.o)

# all rule
all: $(NAME)

%.o:%.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mLibft: Built library. ᕙ(⇀‸↼‶)ᕗ\033[0m"

# clean rule
clean:
	@rm -f $(OBJ)
	@echo "\033[32mLibft: Cleaned up object files. ᕙ(⇀‸↼‶)ᕗ\033[0m"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mLibft: Cleaned up compiled files. ᕙ(⇀‸↼‶)ᕗ\033[0m"

re: fclean all

.PHONY: all clean fclean re
