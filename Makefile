##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

#\033 or \e or \x1B

#set Normal = ? + 20
BOLD='\033[1m'
NBOLD='\033[21m'
BLINK='\033[5m'
REV='\033[7m'
HIDE='\033[8m'
UNDERLIN='\033[4m'
DIM='\033[2m'

#no color
NOCOLR='\033[0m'

#Colors
#BACKGROUND = Color + 10

DEFAULT='\033[39m'
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
MAGENTA='\033[1;35m'
CYAN='\033[1;36m'
LIGHTGRAY='\033[1;37m'
DARKGRAY='\033[1;90m'
LIGHTRED='\033[1;91m'
LIGHTGREEN='\033[1;92m'
LIGHTYELLOW='\033[1;93m'
LIGHTBLUE='\033[1;94m'
LIGHTMAGENTA='\033[1;95m'
LIGHTCYAN='\033[1;96m'
WHITE='\033[1;97m'

#ex for i in {16..21} {21..16} ; do echo -en "\e[38;5;${i}m#\e[0m" ; done ; echo

SRC =	src/torus.c	\
	src/usage.c	\
	src/my_strcmp.c \
	src/check.c \
	src/my_strlen.c

OBJ = $(SRC:.c=.o)

FLAGS = -lm

NAME = 105torus

all: $(NAME)

$(NAME): $(OBJ)
	@echo -en "\033[33;5m    *COMPILING BINARY*\n\e[0m"
	gcc -o $(NAME) $(OBJ) $(FLAGS)

%.o: %.c
	@echo -en "\033[1;31m   Compiling $@...\033[1;37m\n\t"
	gcc -o $@ -c $<

clean:
	@echo -en "\033[1;35m    DELETING .o files...\n"
	rm -rf $(OBJ)

fclean: clean
	@echo -en "\033[1;32m     DELETING Binary ...\n"
	rm -rf $(NAME)

re: fclean all
