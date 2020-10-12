SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BNSOBJS = $(BONUS_SRCS:.c=.o)
INCS = .
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

ifdef BONUS_FLAG
	MATERIALS = $(OBJS) $(BNSOBJS)
else
	MATERIALS = $(OBJS)
endif

$(NAME): $(MATERIALS)
	ar rc $(NAME) $?
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(BNSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	gcc -shared -v $(SRCS) -o libft.so

bonus:
	make BONUS_FLAG=1 all

.PHONY: all clean fclean re bonus .c.o
