SRCS		=	main.c less_six/sort.c stacks/swap.c stacks/push.c stacks/rotate.c \
				stacks/rrotate.c stacks/push_elem.c stacks/get_stacks.c \
				stacks/free_stacks.c stacks/get_stack.c less_six/print_path.c \
				less_six/find_path.c less_six/path.c stacks/inv_ops/inv_swap.c \
				stacks/inv_ops/inv_push.c stacks/inv_ops/inv_rotate.c \
				stacks/inv_ops/inv_rrotate.c stacks/clone_stacks.c \
				stacks/print_stacks.c stacks/inv_ops/inv_op_utils.c \
				general/sort_general.c \
				general/push_below_median.c \
				general/push_everything_but_2_lasts.c \
				general/push_back_to_A_sorted_way.c \
				general/rotate_until_sorted.c \
				stacks/get_double_distance_of.c \
				general/bring_to_the_top.c \
				parse_stack_a.c \
				print_error.c

SRCS_ONLY_CHECK_	=	main.c \
						check_sorting.c

SRCS_ONLY_CHECK	=	$(addprefix checker/, $(SRCS_ONLY_CHECK_))

SRCS_CHECK	=	$(SRCS_ONLY_CHECK) \
				parse_stack_a.c \
				print_error.c \
				stacks/get_stacks.c \
				stacks/get_stack.c \
				stacks/free_stacks.c \
				stacks/push_elem.c \
				stacks/inv_ops/inv_op_utils.c \
				stacks/push.c \
				stacks/rotate.c \
				stacks/rrotate.c \
				stacks/swap.c \
				stacks/inv_ops/inv_rotate.c \
				stacks/inv_ops/inv_swap.c \
				stacks/inv_ops/inv_push.c \
				stacks/inv_ops/inv_rrotate.c \
				libs/get_next_line/get_next_line.c \
				libs/get_next_line/get_next_line_utils.c \

OBJS		:=	${SRCS:.c=.o}

OBJS_CHECK	:=	$(SRCS_CHECK:.c=.o)

NAME		=	push_swap

NAME_CHECK	=	checker

CFLAGS		=	-Wall -Werror -Wextra -g3 -D BUFFER_SIZE=512 #-O0 -fsanitize=address

INCLUDE		=	-I includes/ -I includes/general -I libs/get_next_line -I libs/libdynamic_buffer/includes

OBJS_GNL	=	get_next_line.c get_next_line_utils.c

LIBS		=	libs/libft/libft.a
LIBS_CHECK	=	libs/libdynamic_buffer/libdynamic_buffer.a libs/libft/libft.a

BUILD		=	build/

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

$(NAME)	:	$(addprefix build/,${OBJS})	${LIBS}
	cc ${CFLAGS} -o ${NAME} $(addprefix build/,${OBJS}) ${LIBS}

$(NAME_CHECK)	:	$(addprefix build/, $(OBJS_CHECK)) $(LIBS_CHECK)
	cc $(CFLAGS) -o $(NAME_CHECK) $(addprefix build/,$(OBJS_CHECK)) $(LIBS) $(LIBS_CHECK)

libs/libft/libft.a	:
	make -C libs/libft

libs/libdynamic_buffer/libdynamic_buffer.a	:
	make -C libs/libdynamic_buffer

build/%.o	:	%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} ${INCLUDE} -c $< -o $@

libs/get_next_line/get_next_line.a	:	$(OBJS_GNL)
	ar rc libs/get_next_line/get_next_line.a $(OBJS_GNL)

libs	:	${LIBS}

bonus	:	$(NAME_CHECK)

clean	:	
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

fcleanlibs	:
	make -C libs/libft fclean
	make -C libs/libdynamic_buffer fclean

fcleanall	:	fclean fcleanlibs

re		:	fclean ${NAME}

relibs	:	fcleanlibs	libs

reall	:	relibs re

.PHONY	:	all clean fclean re reall relibs fcleanlibs fcleanall libs bonus
