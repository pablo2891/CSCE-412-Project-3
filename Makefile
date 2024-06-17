CC = g++
CFLAGS = -Wall -Werror
INCLUDES = -Iinclude

# Targets
TARGET = myprogram
SOURCES = src/main.cpp src/request.cpp src/request_queue.cpp src/load_balancer.cpp src/web_server.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJECTS)

# Compile the source files into object files
src/%.o: src/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean the build directory
clean:
	rm -f $(TARGET) $(OBJECTS)
