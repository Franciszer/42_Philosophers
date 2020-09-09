# ___COMPILATION___

CC= cc
FLAGS= -Wall -Wextra -Werror
SRCS=	srcs/main.c\
		srcs/ft_atol.c\
		srcs/get_philo_data.c\
		srcs/ft_perror.c\
		srcs/ft_putchar_fd.c\
		srcs/ft_putendl_fd.c\
		srcs/ft_putnbr_fd.c\
		srcs/ft_putstr.c\
		srcs/ft_putstr_fd.c\
		srcs/ft_strlen.c

NAME= philo_one
OBJS= ${SRCS:.c=.o}
INCLUDE_DIRS = -I .


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
	@printf "${YELLOW}=>	"
	${CC} ${FLAGS} ${INCLUDE_DIRS} ${OBJS} -o ${NAME}
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

