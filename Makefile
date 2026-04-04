NAME        = Skyjo

OBJ_DIR     = objs

RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
CYAN        = \033[0;36m
RESET       = \033[0m

SRCS_PATH		= src/
SRCS        = $(SRCS_PATH)main.cpp\
							$(SRCS_PATH)Card.cpp\
							$(SRCS_PATH)Deck.cpp\
							$(SRCS_PATH)Game.cpp\
							$(SRCS_PATH)Player.cpp

OBJS        = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++11 -I inc
LDLIBS      = -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)🔧 Linking: $(NAME)$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)
	@echo "$(GREEN)✅ Compilation terminée avec succès !$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)📝 Compiling: $<$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)🧹 Cleaning objects...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)🗑️  Full clean...$(RESET)"
	@rm -f $(NAME)

re: fclean all
	@echo "$(GREEN)♻️  Rebuilding project...$(RESET)"

.PHONY: all clean fclean re
