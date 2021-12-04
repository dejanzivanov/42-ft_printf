# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 17:45:40 by dzivanov          #+#    #+#              #
#    Updated: 2021/06/30 20:38:02 by dzivanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS_PATH    = srcs/

LIBFT_PATH    = libft/

LIBFT_OBJSD = obj

LIBFT_SRCD = src

LIBFT_LIB    = libft.a

HEADERS_FOLDER    = inc/

SRCD		=	./src/

SRC 		=	ft_checkers.c ft_handle_alignment.c ft_handlers.c \
				ft_list_updates.c ft_print_char.c ft_print_hexadecimal.c \
  				ft_print_integer.c ft_print_percentage.c ft_print_pointer.c \
				ft_print_string.c ft_print_unsigned_int.c ft_utils.c ft_printf.c

SRCS_FILES	= $(addprefix $(SRCD),$(SRC))
OBJD		= ./obj/

SRCS_OBJS 		= $(SRCS_FILES:$(SRCD)%.c=$(OBJD)%.o)
BUILD 		= $(SRCS_OBJS:$(OBJD)%.o)

CC         = gcc

CFLAGS         = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}${LIBFT_OBJSD}/*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	$(CC) $(CFLAGS) -I ${HEADD} -lbsd -c -o $@ $<


all:				${NAME}

${NAME}:    ${SRCS_OBJS} make
			${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

make:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRCS_OBJS}

fclean: 	clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         fclean all

.PHONY:        all clean fclean re