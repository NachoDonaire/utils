#! /bin/bash
name=$1
mkdir src
mkdir inc
touch Makefile
touch src/"$1".cpp
touch inc/"$1".hpp
echo 'SRCS = '"$1"'.cpp
SRDIR = src/
NAME = '"$1"'
DSRC = $(addprefix $(SRDIR), $(SRCS))
OBJS = $(DSRC:.c=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -Iinc
RM = rm -rf

all: $(NAME)

$(OBJS) : $(DSRC)
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re' > Makefile
echo '#include "'"$1"'.hpp"

int	main(int arg, char **args)
{
	if (arg && args)
		std::cout << "Done!!";
	return (0);
}' > src/"$1".cpp
echo '#include "iostream"
#include "unistd.h"' > inc/"$1".hpp
