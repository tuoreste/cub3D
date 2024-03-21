# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otuyishi <otuyishi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 14:23:29 by otuyishi          #+#    #+#              #
#    Updated: 2024/03/21 17:43:11 by otuyishi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3d

CC := gcc
CFLAGS := -g -Wextra -Wall -Werror -O3 -funroll-loops #-fsanitize=address
LIBMLX := lib/MLX42
LIBFT := lib/libft

HEADERS := -I./include -I$(LIBMLX)/include -I./lib/libft -I./lib/MLX42/include/MLX42
LIBS := $(LIBMLX)/build/libmlx42.a

SRC_DIR := src
SRCS := $(SRC_DIR)/gen_utils.c \
        $(SRC_DIR)/main.c \
        $(SRC_DIR)/movements.c \
        $(SRC_DIR)/parcing.c \
        $(SRC_DIR)/parcing_utils1.c \
        $(SRC_DIR)/parcing_utils2.c \
        $(SRC_DIR)/raycasting.c \
        $(SRC_DIR)/read.c \
        $(SRC_DIR)/rendering.c \
        $(SRC_DIR)/textures.c


SRCS += $(LIBFT)/ft_atoi.c \
        $(LIBFT)/ft_calloc.c \
        $(LIBFT)/ft_split.c \
        $(LIBFT)/ft_strdup.c \
        $(LIBFT)/ft_strjoin.c \
        $(LIBFT)/ft_strlen.c \
        $(LIBFT)/ft_strnstr.c \
        $(LIBFT)/ft_bzero.c \
        $(LIBFT)/ft_isdigit.c \
        $(LIBFT)/ft_memcpy.c \
        $(LIBFT)/ft_strncmp.c \
        $(LIBFT)/ft_strtrim.c \
        $(LIBFT)/ft_substr.c \
        $(LIBFT)/ft_strchr.c \
        $(LIBFT)/ft_strlcpy.c \
        $(LIBFT)/ft_lstadd_front.c \
        $(LIBFT)/ft_memmove.c \
        $(LIBFT)/ft_lstclear.c \
        $(LIBFT)/ft_memset.c \
        $(LIBFT)/ft_lstdelone.c \
        $(LIBFT)/ft_strrchr.c \
        $(LIBFT)/ft_lstiter.c \
        $(LIBFT)/ft_isalnum.c \
        $(LIBFT)/ft_lstlast.c \
        $(LIBFT)/ft_isalpha.c \
        $(LIBFT)/ft_lstmap.c \
        $(LIBFT)/ft_striteri.c \
        $(LIBFT)/ft_tolower.c \
        $(LIBFT)/ft_isascii.c \
        $(LIBFT)/ft_lstnew.c \
        $(LIBFT)/ft_toupper.c \
        $(LIBFT)/ft_lstsize.c \
        $(LIBFT)/ft_strlcat.c \
        $(LIBFT)/ft_isprint.c \
        $(LIBFT)/ft_memchr.c \
        $(LIBFT)/ft_itoa.c \
        $(LIBFT)/ft_memcmp.c \
        $(LIBFT)/ft_lstadd_back.c \
        $(LIBFT)/ft_strmapi.c

OBJS := $(SRCS:.c=.o)

LDFLAGS := -ldl -L$(LIBMLX)/glfw_lib/ -lglfw3 -pthread -lm -flto -framework Cocoa -framework OpenGL -framework IOKit -g -fsanitize=address

all: MLX $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(LDFLAGS) -o $@ && echo "Successful build...!"

MLX:
	@if [ ! -e $(LIBMLX)/build/libmlx42.a ]; then \
		echo "Building libmlx42..."; \
		chmod 755 setup_libs.sh; \
		sh setup_libs.sh; \
	fi

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all MLX libft clean fclean re
