# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masase <masase@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 17:01:35 by maw               #+#    #+#              #
#    Updated: 2024/12/01 14:56:55 by masase           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRCS =	main.c \
		listmanager.c \
		listmanager2.c \
		utils1.c \
		instrument_a.c \
		instrument_b.c \
		instrument_c.c \
		arg_manager.c \
		algo.c \
		findnumbers.c \
		findnumbers2.c \
		rotation_true.c \
		rotation_false.c \
		price_checker.c \
		small_input.c \
		
		
OBJS := $(SRCS:%.c=%.o)

LIBFT = LIBFT

FLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	gcc $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

all: $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all
