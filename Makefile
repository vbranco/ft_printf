# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 16:47:01 by vbranco      #+#   ##    ##    #+#        #
#    Updated: 2018/01/24 20:02:24 by vbranco     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME        =   a.out 

LIB_DIR     =   ./lib

HEADER      =   ft_printf.h

FILENAMES   =   ft_arg_c.c ft_arg_d_i.c ft_arg_p.c ft_arg_s.c ft_arg_x_o.c \
ft_convert_base.c ft_format.c ft_wchar.c ft_init_struct.c ft_printf.c \
ft_args.c ft_recup_flag.c ft_recup_length.c ft_recup_min.c ft_recup_prec.c \
ft_recup_type.c ft_wstr.c ft_count_size.c

SOURCES     =   $(addprefix ./, $(FILENAMES))

OBJECTS     =   $(addprefix build/, $(FILENAMES:.c=.o))

L_FT        =   ./libft

LIB_LNK     =   -L $(L_FT) -l ft

LIB_INC     =   -I $(L_FT)/libft.h

.PHONY: all clean fclean re

all: $(NAME)

clean:
	    @echo "\033[31m"
		rm -rf build/
		@$(MAKE) -C $(L_FT) clean

fclean: clean
	    @echo "\033[31m"
		rm -f $(NAME)
		@$(MAKE) -C $(L_FT) fclean

re:
	    @$(MAKE) fclean
		@$(MAKE) all

build:
	    @echo "\033[35m"
		mkdir build/

$(NAME): $(OBJECTS)
	    @$(MAKE) -C $(L_FT)
		@echo "\033[32m"
		gcc -Wall -Wextra -Werror -I $(HEADER) $(OBJECTS) $(LIB_LNK) -o $@

build/%.o: ./%.c | build
	    gcc -Wall -Wextra -Werror $(LIB_INC) -I $(HEADER) -c $< -o $@
