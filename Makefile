#SETUP
NAME		= minitalk
NAME1		= server
NAME2		= client
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

#FILES
SRCS_DIR	= sources/
HEADER		= $(SRCS_DIR)$(NAME).h

FLS1		= $(NAME1).c utils.c
SRCS1		= $(addprefix $(SRCS_DIR), $(FLS1))
OBJS1		= $(SRCS1:.c=.o)

FLS2		= $(NAME2).c utils.c
SRCS2		= $(addprefix $(SRCS_DIR), $(FLS2))
OBJS2		= $(SRCS2:.c=.o)

#COMMANDS
all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
			@$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1)
			@echo "$(GREEN)$(NAME1) created!$(DEFAULT)"

$(NAME2):	$(OBJS2)
			@$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)
			@echo "$(GREEN)$(NAME2) created!$(DEFAULT)"

$(OBJS1):	$(HEADER)
$(OBJS2):	$(HEADER)

clean:
			@$(RM) $(OBJS1)
			@$(RM) $(OBJS2)
			@echo "$(YELLOW)$(NAME) cleaned!$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME1)
			@$(RM) $(NAME2)
			@echo "$(RED)$(NAME) deleted!$(DEFAULT)"

re:			fclean all

#EXTRA
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m

.PHONY:		all clean fclean re