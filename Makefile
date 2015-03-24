# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by rlambert          #+#    #+#              #
#    Updated: 2015/03/24 21:06:14 by rlambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

PRINTF_PATH ?= ft_printf/

LIBFT_PATH ?= ft_printf/libft/

GNL_PATH ?= gnl/

CFLAGS += -Wall -Wextra -Werror

SRCS = src/ft_sh.c \
	   src/ft_environ.c \
	   src/ft_signals.c \
	   src/ft_unixcmd.c \
	   src/builtins/builtin_cd.c \
	   src/builtins/builtin_env.c \
	   src/builtins/builtin_exit.c \
	   src/builtins/builtin_setenv.c \
	   src/builtins/builtin_unsetenv.c \
	   src/builtins/handle_builtins.c

C_INCLUDE_PATH += $(LIBFT_PATH)/include/ include/ gnl/ $(PRINTF_PATH)/include/

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

all: $(NAME)

MKDIR ?= mkdir

obj/%.o: src/%.c
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PRINTF_PATH)/libftprintf.a:
	$(MAKE) -C $(PRINTF_PATH)

$(GNL_PATH)/libgnl.a:
	$(MAKE) -C $(GNL_PATH)

$(NAME): $(PRINTF_PATH)/libftprintf.a $(GNL_PATH)/libgnl.a $(OBJS)
	$(CC) -o $@ $(OBJS) -L$(PRINTF_PATH) -L$(GNL_PATH) -lgnl -lftprintf

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	$(MAKE) -C $(GNL_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean
	$(MAKE) -C $(GNL_PATH) fclean

re: fclean all


.PHONY: all clean fclean re $(PRINTF_PATH)/libftprintf.a $(GNL_PATH)/libgnl.a
