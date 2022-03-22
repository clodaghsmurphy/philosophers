SRC = src/philo.c \
	src/utils.c \
	src/list.c \
	src/actions.c \
	src/init.c \
	src/routine.c \

CFLAGS = -MMD -Wall -Wextra -Werror -g3
CC = gcc

NAME = philo

DEP = $(SRC:.c=.d)

OBJ = $(SRC:.c=.o)

GREEN = \33[32m

YELLOW = \33[33m

INCLUDE = -I ./include/ \

PTHREAD = -lpthread

nb:=1

all: $(NAME)

.c.o:
	@echo -n "\33[32m"
	@$(CC)  $(INCLUDE) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo -n "\rPHILO Objects compiled : " ${nb} 
	$(eval nb=$(shell echo $$(($(nb)+1))))


$(NAME): $(OBJ)
	@echo -n "\n"
	@$(CC) $(OBJ) $(PTHREAD) $(CFLAGS) -o $(NAME) $(INCLUDE)
	@echo "$(GREEN)   \nLet get philosophical!"

clean:
	@rm -f $(OBJ)
	@rm -f $(DEP)

fclean: clean
	rm -f $(NAME)

-include $(DEP)

.PHONY: all re fclean clean

.SECONDARY: $(OBJ)

re: fclean all