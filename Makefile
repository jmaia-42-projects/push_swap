SRCS		=	main.c less_six/sort.c stacks/swap.c stacks/push.c stacks/rotate.c \
				stacks/rrotate.c stacks/push_elem.c stacks/get_stacks.c \
				stacks/free_stacks.c stacks/get_stack.c less_six/print_path.c \
				less_six/find_path.c less_six/path.c stacks/inv_ops/inv_swap.c \
				stacks/inv_ops/inv_push.c stacks/inv_ops/inv_rotate.c \
				stacks/inv_ops/inv_rrotate.c stacks/clone_stacks.c \
				stacks/print_stacks.c stacks/inv_ops/inv_op_utils.c \
				general/sort_general.c \
				general/rules/rotate_in_the_void.c \
				general/rules/swap_here.c \
				general/rules/get_rules.c \
				general/rules/bubble_merge.c \
				general/rules/hide_and_seek_merge.c \
				general/is_sorted.c \
				general/intcmp.c \
				stacks/get_max.c

OBJS		:=	${SRCS:.c=.o}

NAME		=	push_swap

CFLAGS		=	-Wall -Werror -Wextra -g3 -O0 #-fsanitize=address

INCLUDE		=	-I includes/ -I includes/general

LIBS		=	libs/libft/libft.a

BUILD		=	build/

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

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
