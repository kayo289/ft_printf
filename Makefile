NAME = libftprintf.a

SRCS = \
	srcs/ft_char.c \
	srcs/ft_printf.c \
	srcs/ft_flag.c \
	srcs/ft_treat_num.c \
	srcs/ft_treat_str.c \
	srcs/ft_put.c \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re : fclean all
