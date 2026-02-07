EX_NAME = ex01
C = c++
C_FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS_FILES = Bureaucrat.cpp Form.cpp main.cpp
OBJS_FILES = $(SRCS_FILES:.cpp=.o)

all: $(EX_NAME)

$(EX_NAME): $(OBJS_FILES)
	$(C) $(C_FLAGS) $(OBJS_FILES) -o $(EX_NAME)

%.o: %.cpp %.hpp
	$(C) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_FILES)

fclean: clean
	rm -f $(EX_NAME)

re: fclean all

.PHONY: all clean fclean re

