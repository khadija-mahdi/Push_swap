NAME = push_swap

NAME_BONUS = checker

SRC= ./Mandatory/Instruction/rotate.c\
	./Mandatory/Instruction/push_and_swap.c\
	./libft/utils.c\
	./libft/libft_utils.c \
	./Mandatory/main.c\
	./Mandatory/parsing.c \
	./Mandatory/push_swap.c\
	./Mandatory/sort/short_sort.c\
	./Mandatory/sort/long_sort.c \

BONUS_SRC= ./bonus/bonus_main.c\
		./libft/utils.c\
		./libft/libft_utils.c\
		./bonus/get_next_line/get_next_line.c\
		./bonus/get_next_line/get_next_line_utils.c\
		./bonus/bonus_rotate.c ./bonus/bonus_swap_push.c 
OBJ= $(SRC:.c=.o)

OBJ_BONUS= $(BONUS_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 


$(RM) = rm -f 
  
all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

push: fclean
	git add . && git commit -m "push" && git push

re: fclean all


bonus: $(NAME_BONUS)

clean_bonus:
	$(RM) $(OBJ_BONUS)

fclean_bonus: clean_bonus
	$(RM) $(NAME_BONUS)

re_bonus: fclean_bonus bonus