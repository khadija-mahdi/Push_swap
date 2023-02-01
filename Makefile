NAME = push_swap

SRC= ./Instruction/rotate.c ./Instruction/push_and_swap.c ./utils/utils.c ./utils/libft_utils.c \
	main.c parsing.c push_swap.c sort.c

OBJ= $(SRC:.c=.o)

CC = cc

#CFLAGS = -Wall -Wextra -Werror 
CFLAGS = -fsanitize=address
$(RM) = rm -f 
  
all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ)    -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
push: fclean
	git add . && git commit -m "push" && git push

re: fclean all