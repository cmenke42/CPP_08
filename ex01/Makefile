NAME			:= a.out
CXX				:= c++
RM				:= rm -f

# Directories
OBJDIR			:= obj
SRCDIR			:= src
INCLUDES_DIR	:= includes

# Include paths
INCLUDES		:= -I ${INCLUDES_DIR}

# All source files
SRCS := \
    main.cpp \
	Span.cpp \

# Object files corresponding to each source file
OBJS := $(patsubst %.cpp, ${OBJDIR}/%.o, ${SRCS})

# ---Compiler Flags---
# Production flags
CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS += -std=c++98 -pedantic
# CXXFLAGS += -O2

# Development flags
CXXFLAGS += -g -O0
CXXFLAGS += -fsanitize=undefined
CXXFLAGS += -fsanitize=address

# Add includes
CXXFLAGS += ${INCLUDES}

# Generating dependencies for user headers automaticly
CXXFLAGS += -MMD 

# Rules
all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME}

${OBJDIR}/%.o: ${SRCDIR}/%.cpp | ${OBJDIR}
	mkdir -p $(dir $@)
	${CXX} ${CXXFLAGS} -c $< -o $@

${OBJDIR}:
	mkdir -p ${OBJDIR}

clean:
	${RM} -r ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

# adding the dependcies as rules and not complainging (-) if file not existent
-include ${OBJS:.o=.d}

.PHONY: all clean fclean re
.NOTPARALLEL:
