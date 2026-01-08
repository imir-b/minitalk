# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbleskin <vbleskin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/04 02:46:01 by vbleskin          #+#    #+#              #
#    Updated: 2026/01/08 20:19:42 by vbleskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------------------------------------------------------
# EXE
# ------------------------------------------------------------------------------

SERVER			=	server
CLIENT			=	client

# ------------------------------------------------------------------------------
# DIRECTORIES
# ------------------------------------------------------------------------------

SERVER_DIR		=	server_src/
CLIENT_DIR		=	client_src/
LIB_DIR			=	lib/
LIBFT_DIR		=	$(LIB_DIR)libft/

# ------------------------------------------------------------------------------
# FLAGS
# ------------------------------------------------------------------------------

MAKEFLAGS 		+=	--no-print-directory
LIBS			=	-L$(LIBFT_DIR) -lft

# ------------------------------------------------------------------------------
# RULES
# ------------------------------------------------------------------------------

all:
	@make -C $(LIBFT_DIR)
	@make -C $(SERVER_DIR)
	@make -C $(CLIENT_DIR)
	@cp $(SERVER_DIR)$(SERVER) .
	@cp $(CLIENT_DIR)$(CLIENT) .

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(SERVER_DIR) clean
	@make -C $(CLIENT_DIR) clean

fclean:
	@make -C $(LIBFT_DIR) fclean
	@make -C $(SERVER_DIR) fclean
	@make -C $(CLIENT_DIR) fclean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re