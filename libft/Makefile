# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 18:26:55 by gamoreno          #+#    #+#              #
#    Updated: 2023/05/11 11:47:30 by dnieto-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Compilation ###

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I

### Executable ###

NAME	=	libft.a

### Inculdes ###

OBJ_PATH = objs
HEADER = includes
SRC_PATH = sources

### Source Files ###

SOURCES	= 	ft_abs.c ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
			ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_substr.c \
			ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
			ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
			ft_memmove.c ft_putnbr_fd.c  ft_strdup.c ft_strlen.c  ft_strrchr.c \
			ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
			ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
			ft_abs.c ft_strcmp.c ft_atof.c ft_ftoa.c ft_atoli.c \
			ft_free_split.c ft_strlen_int.c ft_strjoin_secure.c \
			ft_strnstr_int.c ft_strchr_int.c ft_length_split.c ft_concatenation.c\
			ft_tabdup.c ft_get_index_char_str.c ft_strdup_i.c ft_idx_last_occur_char.c\
			ft_swap_dp.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			get_next_line.c
			

### Objects ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))
DEPS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.d))

### COLORS ###
NOC         = \033[0m
GREEN       = \033[1;32m
CYAN        = \033[1;36m

### RULES ###

all:		tmp $(NAME)

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)
		@echo "$(GREEN)libft made succesfully$(NOC)"

tmp:
		@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		@$(CC) $(FLAGS) -MMD -c -o $@ $<
		@echo "$(CYAN)Creation of object file -> $(CYAN)$(notdir $@)... $(GREEN)[Done]$(NOC)"

clean:
		rm -rf $(OBJ_PATH)


fclean:		clean
		rm -f $(NAME)

re:		fclean all

-include $(DEPS)

.PHONY:		all clean fclean re bonus
