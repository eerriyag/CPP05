EX_NAME = ex00
C = c++
C_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = main.cpp Bureaucrat.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(EX_NAME)

$(EX_NAME): $(OBJ_FILES)
	$(C) $(C_FLAGS) $(OBJ_FILES) -o $(EX_NAME)

%.o: %.cpp %.hpp
	$(C) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(EX_NAME)

re: fclean all

.PHONY: all clean fclean re

