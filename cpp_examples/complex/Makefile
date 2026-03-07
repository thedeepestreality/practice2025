CC=g++
CFLAGS=-c -Werror
LDFLAGS=
SOURCES=main.cpp complex.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=complex

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)

# main.o:
# 	g++ -c main.cpp -o main.o

# complex.o:
# 	g++ -c complex.cpp -o complex.o