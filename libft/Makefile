NAME	=	libft.a

HEADER	=	libft.h

SRCS	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_strjoin.c ft_strlen.c ft_isalpha.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_strlcpy.c ft_strlcat.c ft_memcpy.c ft_memset.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
				ft_calloc.c ft_substr.c ft_strtrim.c ft_strmapi.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c

BSRCS		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

BOBJS		=	$(BSRCS:.c=.o)
OBJS		=	$(SRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus:	$(BOBJS) $(OBJS)
	ar rc $(NAME) $(BOBJS) $(OBJS)

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re