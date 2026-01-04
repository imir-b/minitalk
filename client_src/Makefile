# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/04 02:10:08 by vbleskin          #+#    #+#              #
#    Updated: 2026/01/04 03:35:07 by vbleskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# NAME

NAME			=	client

# DEF

CC				= cc
CFLAGS			= -Wall -Werror -Wextra -I ../includes -I $(LIBFT_DIR)includes -g3
MAKEFLAGS 		+=	--no-print-directory
RM				= rm -rf

# DIR

SRC_DIR			=	src/
OBJ_DIR			=	obj/
LIB_DIR			=	../lib/
LIBFT_DIR		=	$(LIB_DIR)libft/

# FILES

SRC_FILES		=	main.c
SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS			=	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
LIBS			=	-L$(LIBFT_DIR) -lft

# RULES

all :			$(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "Compiling $<"

$(NAME) :		$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
				@echo "$(NAME) compiled successfuly"

clean :
				@$(RM) $(OBJ_DIR)
				@echo "$(NAME) cleaned successfuly"

fclean :		clean
				@$(RM) $(NAME)

re :			fclean all

.PHONY:			all clean fclean re