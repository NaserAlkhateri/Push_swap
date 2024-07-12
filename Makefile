CFLAGS = -Wall -Werror -Wextra
SOURCES =  main.c push_swap.c ft_split.c list_utils.c number_utils.c\
			stack_a.c stack_b.c stack_both.c sorting.c stack_utils.c\
			target_utils.c stack_op.c sorting_utils.c cost_utils.c

BSOURCES = checker_bonus.c get_next_line.c get_next_line_utils.c \
			push_swap.c ft_split.c list_utils.c number_utils.c\
			stack_a.c stack_b.c stack_both.c sorting.c stack_utils.c\
			target_utils.c stack_op.c sorting_utils.c cost_utils.c	
CC = cc
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(BONUS_NAME): $(BOBJECTS)
	$(CC) $(CFLAGS) $(BOBJECTS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJECTS) $(BOBJECTS) 

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all