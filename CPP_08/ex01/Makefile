NAME = Span
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

SRCS = \
	src/Span.cpp \
	src/main.cpp \

OBJS_DIR = obj
OBJS = $(SRCS:src/%.cpp=$(OBJS_DIR)/%.o)
DEP = $(OBJS:.o=.d)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: src/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re:
	@make fclean
	@make all

-include $(DEP)

.PHONY: all clean fclean re