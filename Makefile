NAME		= push_swap
SRCS		= $(shell find "." -name "*.c" ! -name "checker.c" ! -path "./bonus/*.c")
OBJS		= $(SRCS:.c=.o)
BONUS_SRCS = $(shell find "." -name "*.c" ! -name "push_swap.c")
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
INCS		= -I.
CFLAGS		= -g -Wall -Wextra -Werror $(INCS)
RM			= rm -f
CC			= cc
AR			= ar rcs

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus: ${BONUS_OBJS}
	$(CC) $(CFLAGS) -o checker $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all

.PHONY: all clean fclean re
