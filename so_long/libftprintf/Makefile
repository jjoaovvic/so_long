SRCS	=	ft_printf.c ft_printchar.c ft_printhex.c ft_printnbr.c \
				ft_printpnt.c ft_printstr.c ft_printunsg.c

OBJS	= $(SRCS:.c=.o)

NAME	=	libftprintf.a

CFLAGS	+=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	make all -C libft/
	cp ./libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f ${OBJS} ${OBJS_BONUS}
	make clean -C libft/

fclean:	clean
	rm -f ${NAME}
	make fclean -C libft/

re:	fclean all

.PHONY:	all clean fclean re