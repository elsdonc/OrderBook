CXX      = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# our target program
TARGET   = main

# source and object files
SRCS     = main.cc Order.cc OrderBook.cc
OBJS     = $(SRCS:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# generic rule: compile .cc → .o
%.o: %.cc Order.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
