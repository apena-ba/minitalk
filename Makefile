NAME = server
NAME_C = client

NAME_BONUS = server_bonus
NAME_C_BONUS = client_bonus

INC = -I libft/includes

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: ${NAME} ${NAME_C}

${NAME}: ${LIBFT} src/server.c
	@gcc ${CFLAGS} -o ${NAME} ${INC} ${LIBFT} src/server.c
	@echo "\n🖥 Programa servidor creado ✅\n"

${NAME_C}:  ${LIBFT} src/client.c
	@gcc ${CFLAGS} -o ${NAME_C} ${INC} ${LIBFT} src/client.c
	@echo "\n👨‍💻 Programa cliente creado ✅\n"

${LIBFT}:	libft/src/*.c
	@make -C libft/ --silent
	@echo "\n📕 Libft compilada ✅\n"

clean:
	@make -C libft/ clean --silent
	@echo "\n🧹 Libft limpia ✅\n"

fclean: clean
	@make -C libft/ fclean --silent
	@rm -f ${NAME}
	@rm -f ${NAME_C}
	@rm -f ${NAME_BONUS}
	@rm -f ${NAME_C_BONUS}
	@echo "\n💥 Archivos binarios destruidos ✅\n"

sclean: fclean
	@rm -f *.o

re: fclean all

sre: sclean all

bonus: ${NAME_BONUS} ${NAME_C_BONUS}

${NAME_BONUS}: ${LIBFT} src_bonus/server_bonus.c
	@gcc ${CFLAGS} -o ${NAME_BONUS} ${INC} ${LIBFT} src_bonus/server_bonus.c
	@echo "\n🖥 Programa servidor bonus creado ✅\n"

${NAME_C_BONUS}: ${LIBFT} src_bonus/client_bonus.c
	@gcc ${CFLAGS} -o ${NAME_C_BONUS} ${INC} ${LIBFT} src_bonus/client_bonus.c
	@echo "\n🖥 Programa cliente bonus creado ✅\n"

.PHONY: all clean fclean sclean re sre
