INCLUDES= includes

_HEADERS= ft_printf.h libft.h

HEADERS = $(patsubst %, $(INC)/%,$(_HEADERS))

SRCS		= parsing/parse_input.c parsing/parse_utils.c parsing/parse.c \
				read/read_utils.c read/read_value.c width_utils/count_base.c \
				width_utils/count_digits.c width_utils/count_ptr.c \
				width_utils/count_width.c other_utils/ft_is_it_in.c \
				other_utils/fill_str.c other_utils/ft_negative_check.c \
				other_utils/ft_putchar.c other_utils/ft_putnbr.c \
				other_utils/intcmp.c other_utils/alignment.c other_utils/ft_convert.c \
				other_utils/ft_putnbr_base.c other_utils/ft_putptr.c other_utils/ft_putstr.c \
				print/print_char.c print/print_int.c print/print_pointer.c \
				print/print_string.c print/print_unsigned.c print/print.c \
				other_utils/ft_putstr_custom.c ft_printf.c

OBJS		= $(patsubst %.c,%.o,$(SRCS))

_LIBFTSRCS	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_strjoin.c ft_strlen.c ft_isalpha.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_strlcpy.c ft_strlcat.c ft_memcpy.c ft_memset.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strnstr.c \
				ft_calloc.c ft_substr.c ft_strtrim.c ft_strmapi.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

LIBFTSRCS	= $(patsubst %,$(LIBFTDIR)/%,$(_LIBFTSRCS))

FTOBJS  = $(patsubst %.c,%.o,$(FTSRCS))

NAME		= libftprintf.a

CC			= gcc

CFLAGS	= -Wall -Wextra -Werror

RM			= rm -f

LIBFTDIR= libft

LIBFTBIN= libft.a

MAKE		= make

all:	$(NAME)

%.o : %.c $(HEADERS)
			$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(FTOBJS)
			$(MAKE) -C $(LIBFTDIR)
			cp $(LIBFTDIR)/$(LIBFTBIN) $(NAME)
			ar rc $(NAME) $(OBJS)

clean:
			$(MAKE) -C libft clean
			$(RM) $(OBJS)

fclean:	clean
			$(MAKE) -C libft fclean
			$(RM) $(NAME)

re:		fclean all

.PHONY:	clean fclean re all
