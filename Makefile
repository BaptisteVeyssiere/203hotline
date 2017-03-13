##
## Makefile for 42sh in /home/VEYSSI_B/rendu/Programmation_Shell/test/test_42tree
##
## Made by Baptiste veyssiere
## Login   <VEYSSI_B@epitech.net>
##
## Started on  Wed May 18 21:26:30 2016 Baptiste veyssiere
##

NAME	= 203hotline

RM	= rm -f

CXX	= g++

MKDIR	= mkdir -p

SRC	= src/main.cpp \
	src/calc.cpp

SRCDIR	= src

OBJDIR	= obj

OBJ	= $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(NAME): $(OBJ)
	@$(CXX) -o $(NAME) $(OBJ)
	@echo "Linking complete!"

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(MKDIR) $(OBJDIR)
	@$(CXX) -c $< -o $@
	@echo "Compiled "$<" successfully!"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@echo "Cleanup complete!"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
