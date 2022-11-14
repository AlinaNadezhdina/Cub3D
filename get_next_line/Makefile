INC			=   get_next_line.h

INC_B		=   get_next_line_bonus.h

SRCS		=	get_next_line.c		get_next_line_utils.c

SRCS_B		=	get_next_line_bonus.c		get_next_line_utils_bonus.c

OBJS		=	$(SRCS:.c=.o)

OBJS_B		=	$(SRCS_B:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

NAME		=	get_next_line.a

all:			$(NAME)

$(NAME):		$(OBJS) $(INC)
				ar rcs $(NAME)  $?

.o:				%.c $(INC)
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
				$(RM) $(OBJS) $(OBJS_B)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus

bonus:			$(OBJS_B) $(INC_B)
				ar rcs $(NAME)  $?
