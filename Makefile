# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 14:43:16 by kesaitou          #+#    #+#              #
#    Updated: 2025/11/18 09:31:59 by kesaitou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra

DEBUG_FLAGS = -g3
SAN_FLAGS = -g3 -fsanitize=address,undefined -fno-omit-frame-pointer


LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

LIBDIR = $(LIBFTDIR)
LDFLAGS = -L $(LIBDIR)
LDLIBS = -lft


MAND_SRCS = main.c\
			main_process.c\
			child_process.c\
			exec_cmd.c\
			exec_utils.c\
			handle_error.c\
			free_utils.c\
			init_args.c\
			here_doc_bonus.c\


MAND_OBJS = $(MAND_SRCS:.c=.o)


all : $(NAME)

	
$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME):$(MAND_OBJS) $(LIBFT)
	$(CC) $(MAND_OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

bonus: $(NAME)
	
%.o : %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(DEBUG_FLAGS)" all

debug_san: fclean
	$(MAKE) CFLAGS="$(CFLAGS) $(SAN_FLAGS)" \
	        LDLIBS="$(LDLIBS) $(SAN_FLAGS)" all
clean:
	rm -f $(MAND_OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all


.PHONY: all clean fclean re