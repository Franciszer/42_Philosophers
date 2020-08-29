# ___COMPILATION___

CC= cc
FLAGS= -Wall -Wextra -Werror
SRCS=	srcs/main.c\
		srcs/get_philo_data.c

NAME= philo_one
OBJS= ${SRCS:.c=.o}
INCLUDE_DIRS = -I . -I srcs/libft
LIB= srcs/libft/libft.a


.c.o:
	@printf "${LIGHT_BLUE}=>	"
	${CC} ${FLAGS} ${INCLUDE_DIRS} -c $< -o ${<:.c=.o}
	@printf "${NC}"

# ___COLORS___

GREEN=\033[0;32m
LIGHT_BLUE=\033[0;34m
RED=\033[0;31m
YELLOW=\033[0;33m
NC=\033[0m

all: ${NAME}

${NAME}: ${OBJS}
	@make -C srcs/libft
	@printf "${YELLOW}=>	"
	${CC} ${FLAGS} ${INCLUDE_DIRS} ${OBJS} ${LIB} -o ${NAME}
	@echo "${GREEN}✓ ${NAME} compiled${NC}"

start: all
	@./${NAME}

valgrind_start: all
	@valgrind --leak-check=full --show-leak-kinds=definite ./${NAME}

clean:
	@printf "${RED}X "
	rm -rf ${OBJS}
	@printf "${NC}"
	@echo "${GREEN}✓ ${NAME} clean${NC}"

fclean: clean
	@printf "${RED}X "
	rm -rf ${NAME}
	@printf "${NC}"

re: fclean all

.PHONY: all clean fclean re start

