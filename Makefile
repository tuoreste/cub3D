# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 14:23:29 by otuyishi          #+#    #+#              #
#    Updated: 2024/01/16 16:29:39 by otuyishi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d

CFLAGS := -Wextra -Wall -Werror -g -O3 -funroll-loops -fsanitize=address
LIBMLX := lib/MLX42

HEADERS := -I ./include -I $(LIBMLX)/include -I ./lib/libft -I ./lib/MLX42/include/MLX42 -I ./lib/get_next_line
LIBS := $(LIBMLX)/build/libmlx42.a

SRC_DIR = source
SRCS = $(addprefix $(SRC_DIR)/, \
main.c \
cub3d.c \
cub_utils.c) \

LDFLAGS := -ldl -L $(LIBMLX)/glfw_lib/ -lglfw3 -pthread -lm -flto -framework Cocoa -framework OpenGL -framework IOKit -fsanitize=address
OBJS := $(SRCS:.c=.o) 

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LDFLAGS) -o $(NAME) && echo "Successful build...!"

MLX:
	@if [ ! -e $(LIBMLX)/build/libmlx42.a ]; then \
		echo "Building libmlx42..."; \
		chmod 755 setup_libs.sh; \
		sh setup_libs.sh; \
	fi

rmlib:
	rm -rf MLX42

clean:
	@rm -rf $(OBJS)

fclean: clean
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all rmlib clean fclean re MLX
