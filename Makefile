##
## EPITECH PROJECT, 2024
## ak-axolotl
## File description:
## Makefile
##

#-----------------------------------------------------------------------------#
## COMPILER OPTIONS

CC 		:=	gcc

NAME	:=	my_rpg

FLAGS	:=	-Wall \
			-Wextra \
			-g \
			-g3 \
			-Iinclude

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
## DEPENDENCIES

LIBS	:=	-lcsfml-system \
			-lcsfml-window \
			-lcsfml-graphics \
			-lcsfml-network \
			-lcsfml-audio \
			-lm

TESTLIB	:=	-lcriterion \
			--coverage

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
## SOURCES

LIBDIR	:=	./libmy/char \
			./libmy/memory \
			./libmy/parsing \
			./libmy/puts \
			./libmy/strings
LIBMY	:=	$(shell find $(LIBDIR) -name '*.c')

TESTDIR	:= 	./tests/
TESTS 	:=	$(shell find $(TESTDIR) -name '*.test.c')

SRCDIR	:= 	./source/
SOURCES	:=	$(shell find $(SRCDIR) -name '*.c')

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
## MISC

FIND	:=	find -type f -iname

RM		:= 	rm -f

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
## COMPILATION

$(NAME):
	$(CC) -o $(NAME) $(SOURCES) $(LIBMY) $(LIBS) $(FLAGS)

all: $(NAME)

re: fclean all

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
## CLEANING

clean:
	$(FIND) "*.o" -delete
	$(FIND) "*.a" -delete

fclean: clean
	$(RM) $(NAME)

tests_clean:
	$(FIND) "*.gcno" -delete
	$(FIND) "*.gcda" -delete
	$(FIND) "*.html" -delete
	$(FIND) "*.css" -delete

tests_fclean: tests_clean
	$(RM) unit_tests

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
## TESTS

tests_build:
	$(CC) -o unit_tests $(TESTS) $(LIBMY) $(FLAGS) $(TESTLIB) $(LIBS)

tests_run: tests_build
	./unit_tests && gcovr -e $(TESTDIR) && gcovr -e $(TESTDIR) -b

tests_re: tests_fclean tests_run

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
## CODING-STYLE

style:
	coding-style . . | grep "coding style error(s)"

#-----------------------------------------------------------------------------#
