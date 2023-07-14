SRCS =  main.c so_long_utils.c checkerror.c fonction.c checkpass.c jeu.c jeu2.c \
		jeu3.c \

SRCS_B = ${addprefix ${SO_LONG_B}, /main.c \
		so_long_utils.c \
		checkerror.c \
		fonction.c \
		checkpass.c \
		jeu.c \
		jeu2.c \
		jeu3.c}

SO_LONG_B = ./so_long_bonus/
OBJS_B = ${SRCS_B:.c=.o}
OBJS_MAIN = ${SRCS:.c=.o}
NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
FLAGSMLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
LIBFT = ./libft

RESET = \033[0m
GRAS = \033[1m
ITALIQUE = \033[3m
SOULIGN = \033[4m
UP = \033[A
BLINK = \033[6m

ORANGE = \033[38;5;216m
DARKBLUE = \033[38;5;21m
RED = \033[38;5;130m
GREEN = \033[38;5;85m

ifndef BONUS
OBJS = $(OBJS_MAIN)
else
OBJS = $(OBJS_B)
endif

FICH_COUNT = 0
NBR_TOT_FICHIER = 8
NBR_COMPILER = ${shell expr 100 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}
BAR =  ${shell expr 23 \* ${FICH_COUNT} / ${NBR_TOT_FICHIER}}


${MAIN_PATH}%.o:%.c .
	@${eval FICH_COUNT = ${shell expr ${FICH_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I . $< -o ${<:.c=.o}
	@echo ""
	@echo " ${GRAS}${RED}-> COMPILATION EN COURS${RESET}${GRAS}${GREEN}[SO_LONG]${RESET}"
	@printf " ${RED}${GRAS}[${GREEN}%-23.${BAR}s${RED}] [%d/%d (%d%%)]${RESET}" "-----------------------" ${FICH_COUNT} ${NBR_TOT_FICHIER} ${NBR_COMPILER}
	@echo "${UP}${UP}${UP}"

all : ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ${LIBFT}/
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT}/libft.a -o ${NAME} ${FLAGSMLX}
	@echo "\n\n\n ${GRAS}${RED}SO_LONG EST COMPILÉ 👏${RESET}\n"

bonus :
	@$(MAKE) BONUS=1
clean:

	@${MAKE} clean -C ${LIBFT}
	@${RM} ${OBJS_MAIN} ${OBJS_B}
	@echo "${ORANGE}${GRAS}\tNETTOYAGE 🛁${RESET}"
	@echo "${DARKBLUE}${ITALIQUE} -les fichiers sont supprimés${RESET}"

fclean: clean
	@${RM} ${NAME} ${LIBFT}/libft.a
	@echo "${DARKBLUE}${ITALIQUE} -libft.a est supprimé${RESET}"
	@echo "${DARKBLUE}${ITALIQUE} -${NAME} est supprimê${RESET}"
re: fclean all

.PHONY: all clean fclean re
