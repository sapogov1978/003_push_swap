# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brattles <brattles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 22:39:05 by brattles          #+#    #+#              #
#    Updated: 2021/09/01 00:14:19 by brattles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CC			:= gcc
WFLAGS		:= -Wall -Wextra -Werror

INC_DIR		:= includes
OBJ_DIR		:= build
FT_DIR		:= libft

FUNCTIONS	= push_swap.c \
			  ft_panic.c \
			  ft_parser.c \
 			  ops/pa.c \
   			  ops/pb.c \
			  ops/p_ops.c \
			  ops/ra.c \
   			  ops/rb.c \
			  ops/rr.c \
			  ops/r_ops.c \
			  ops/sa.c \
 			  ops/sb.c \
			  ops/ss.c \
			  ops/s_ops.c \
   			  ops/rra.c \
			  ops/rrb.c \
   			  ops/rrr.c \
			  ops/rr_ops.c \
			  ft_is_sorted.c \
			  ft_solve_and_print.c \
			  ps_utls.c \
			  lst_indexing.c \
			  ft_bool_isdigit_str.c


OBJ			:= $(FUNCTIONS:%.c=$(OBJ_DIR)/%.o)
DEP			:= $(OBJ:%.o=%.d)
CFLAGS		:= $(WFLAGS) -O3 -MMD
LFLAGS		:= -lft
FT_LIB		+= -L$(FT_DIR)

LIB			:= $(FT_LIB)
INC			:= -I$(FT_DIR) -I$(INC_DIR)

vpath %.c src

.PHONY:	all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJ)
	make -sC $(FT_DIR) all
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) $(LFLAGS) -o $(NAME)

-include $(DEP)
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	make -sC $(FT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(FT_DIR) fclean
	rm -rf $(NAME)

re: fclean all