# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masase <masase@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 17:01:35 by maw               #+#    #+#              #
#    Updated: 2024/11/29 14:43:44 by masase           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap.a

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
	cp $(LIBFT)/libft.a .
	mv libft.a $(NAME)
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean :
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all
