SRCS		=	main.c sort.c stacks/swap.c stacks/push.c stacks/rotate.c \
				stacks/rrotate.c stacks/push_elem.c

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME		=	push_swap

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes/

LIBS		=	libs/libft/libft.a

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@ -g3

$(NAME)	:	$(addprefix build/,${OBJS})	${LIBS}
	cc ${CFLAGS} -o ${NAME} $(addprefix build/,${OBJS}) ${LIBS}

libs/libft/libft.a	:
	make -C libs/libft

libs	:	${LIBS}

clean	:	
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

fcleanlibs	:
	make -C libs/libft fclean

re		:	fclean ${NAME}

relibs	:	fcleanlibs	libs

reall	:	re relibs

.PHONY	:	all clean fclean re reall relibs fcleanlibs libs
