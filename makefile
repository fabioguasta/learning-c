CC=gcc
CFLAGS=-c
LDFLAGS=

EXECUTABLE=sequenza
SOURCES=sequenza.c util.c sysmacro.h
OBJECTS=$(SOURCES:.c=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

util.o: util.h

clean:
	rm -rf *.o $(EXECUTABLE)