



NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h ./libft/libft.h

SRC = ft_arg_c.c ft_arg_d_i.c ft_arg_p.c ft_arg_s.c ft_arg_x_o.c \
ft_convert_base_uintmax.c ft_convert_base_intmax.c ft_format.c ft_wchar.c \
ft_init_struct.c ft_printf.c ft_percent.c\
ft_args.c ft_recup_flag.c ft_recup_length.c ft_recup_min.c ft_recup_prec.c \
ft_recup_type.c ft_wstr.c ft_count_size.c ft_my_itoa.c ft_my_itoa2.c\
ft_size_nb2.c ft_add_str_begin.c\
ft_add_str_end.c ft_buffer_d_i.c ft_arg_b.c ft_buffer_x_o.c ft_buffer_b.c\
ft_buffer_s.c ft_buffer_c.c

LIBSRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_isblank.c ft_isupper.c ft_isxdigit.c ft_isspace.c ft_islower.c \
ft_size_nb.c ft_reverse.c ft_count_words.c

LIBOBJS = $(addprefix ./libft/, $(LIBSRC:.c=.o))

LIBSRCS = $(addprefix ./libft/, $(LIBSRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBOBJS)
	ar -rc $@ $^

%.o: %.c
	gcc -c $< -o $@ $(FLAGS)

clean:
	/bin/rm -f $(OBJ) $(LIBOBJS) ft_printf.h.gch ./libft/libft.h.gch ./libft/libft.a

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
