# ==========================
# Makefile for ex02
# ==========================

EX_NAME = ex02
C = c++
C_FLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS_FILES = main.cpp \
             Bureaucrat.cpp \
             AForm.cpp \
             ShrubberyCreationForm.cpp \
             RobotomyRequestForm.cpp \
             PresidentialPardonForm.cpp

# Object files
OBJS_FILES = $(SRCS_FILES:.cpp=.o)

# ==========================
# Rules
# ==========================

all: $(EX_NAME)

# Linking
$(EX_NAME): $(OBJS_FILES)
	$(C) $(C_FLAGS) $(OBJS_FILES) -o $(EX_NAME)

# Compiling
%.o: %.cpp %.hpp
	$(C) $(C_FLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS_FILES)

# Full clean (object files + executable)
fclean: clean
	rm -f $(EX_NAME)

# Rebuild all
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re
