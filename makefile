NAME = program

CC = c++ 
SRC = test.cpp
# HEADER = Array.hpp 
OBJ_F = $(SRC:%.cpp=%.o)
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME) : $(OBJ_F) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ_F) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_F)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re