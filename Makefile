##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME = nanotekspice

SRC = *.cpp

FLAGS = -std=c++20 -Wall -Wextra -Werror -g3

all:
	g++ -o $(NAME) $(SRC) $(FLAGS)

clean:
	rm -f *~ | rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
