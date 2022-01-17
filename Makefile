SRCS		=	main.c sort.c stacks/swap.c stacks/push.c stacks/rotate.c \
				stacks/rrotate.c stacks/push_elem.c stacks/get_stacks.c \
				stacks/free_stacks.c stacks/get_stack.c print_path.c \
				find_path.c stacks/inv_ops/inv_swap.c \
				stacks/inv_ops/inv_push.c stacks/inv_ops/inv_rotate.c \
				stacks/inv_ops/inv_rrotate.c

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
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@

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

fcleanall	:	fclean fcleanlibs

re		:	fclean ${NAME}

relibs	:	fcleanlibs	libs

reall	:	relibs re

.PHONY	:	all clean fclean re reall relibs fcleanlibs fcleanall libs
