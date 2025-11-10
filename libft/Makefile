# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/18 16:54:22 by kesaitou          #+#    #+#              #
#    Updated: 2025/11/09 18:23:20 by kesaitou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC := cc
CFLAGS := -Wall -Werror -Wextra -I includes
AR := ar
ARFLAGS := rcs

LIBC_DIR := ft_libc

PRINTF_DIR := ft_printf

GNL_DIR := gnl

LIBC_SRCS := \
	ft_itoa.c ft_putstr_fd.c ft_strmapi.c ft_isalpha.c \
	ft_memmove.c ft_strlcat.c ft_strrchr.c ft_atoi.c \
	ft_putchar_fd.c ft_split.c ft_strtrim.c ft_isascii.c \
	ft_memchr.c ft_memset.c ft_strlcpy.c ft_tolower.c \
	ft_bzero.c ft_putendl_fd.c ft_striteri.c ft_substr.c \
	ft_isdigit.c ft_memcmp.c ft_strchr.c ft_strlen.c \
	ft_toupper.c ft_calloc.c ft_putnbr_fd.c ft_strjoin.c \
	ft_isalnum.c ft_isprint.c ft_memcpy.c ft_strdup.c \
	ft_strncmp.c ft_strnstr.c ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF_SRCS := \
	ft_printf.c \
	libft_utils.c \
	uxx_helper.c \
	parse.c \
	print_csper.c \
	print_di.c \
	print_uxx.c \
	print_p.c \
	print.c \
	utils.c

GNL_SRCS := \
	get_next_line.c \
	get_next_line_utils.c

SRCS := \
    $(addprefix $(LIBC_DIR)/, $(LIBC_SRCS)) \
    $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS)) \
    $(addprefix $(GNL_DIR)/, $(GNL_SRCS))


OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all