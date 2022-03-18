SRC = src/philo.c \
	src/utils.c \
	src/list.c \

LIBFT_PATH = ./Libft/

CFLAGS = -MMD -Wall -Wextra -Werror -g3
CC = gcc

NAME = philo

DEP = $(SRC:.c=.d)

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./include/ \
		-I ./Libft/

Libft = Libft/libft.a

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
	@make -C Libft
	@$(CC) $(OBJ) $(PTHREAD) $(CFLAGS) $(Libft) -o $(NAME) $(INCLUDE)
	@echo "\nLet get philosophical!"

clean:
	@rm -f $(OBJ)
	@rm -f $(DEP)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean


-include $(DEP)

.PHONY: all re fclean clean

.SECONDARY: $(OBJ)

re: fclean all