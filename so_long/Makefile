SRCS	=	so_long.c read_map.c errormanager.c move.c \
			render.c testmap.c freestuff.c test_letters.c

OBJS	= $(SRCS:.c=.o)

NAME	=	so_long

CFLAGS	+=	-Wall -Werror -Wextra

LIBFT = libftprintf/libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
	make -C libftprintf/
	cc $(CFLAGS) -I libftprintf -I libftprintf/libft $(OBJS) -Imlx -lmlx -lX11 -lXext $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f ${OBJS} ${OBJS_BONUS}
	make clean -C libftprintf/

fclean:	clean
	rm -f ${NAME}
	make fclean -C libftprintf/

re:	fclean all

.PHONY:	all clean fclean re