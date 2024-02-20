# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 13:24:16 by mpierrot          #+#    #+#              #
#    Updated: 2024/02/18 22:25:32 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR = includes
SRCDIR = srcs
OBJDIR = objs

SRCS = 	srcs/get_next_line.c \
		srcs/get_next_line_utils.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME = get_next_line
CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
RM = rm -rf
AR = ar rcs

DFCOLOR	= \033[0;39m
GREEN	= \033[0;92m
YELLOW	= \033[0.93m
BLUE	= \033[0.94m
CYAN	= \033[0;96m

all: $(NAME)

@$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN) GNL has been successfully compiled$(DEFCOLOR)"

@$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -I $(HDRDIR) -c $< -o $@

clean:
	@$(RM) objs
	@echo "$(BLUE)GNL object files cleaned! $(DEFCOLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN) GNL executable has been cleaned! $(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN) Cleaned and rebuilt successfully! $(DEFCOLOR)"

.PHONY: all clean fclean re