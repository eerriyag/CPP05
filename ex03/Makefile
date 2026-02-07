# ==========================
# Makefile for ex03
# ==========================

EX_NAME = ex03             # Nom de l'exécutable pour cet exercice
C = c++
C_FLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS_FILES = main.cpp \
             Bureaucrat.cpp \
             AForm.cpp \
             ShrubberyCreationForm.cpp \
             RobotomyRequestForm.cpp \
             PresidentialPardonForm.cpp \
             Intern.cpp         # On ajoute Intern.cpp pour ex03

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

