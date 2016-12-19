CC = clang
CFLAGS = -g -O2 -Wall

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
TARGET  = build/gpgdir

all: $(OBJECTS)
	mkdir -p build
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) -c $(CC_FLAGS) $< -o $@

install:
	cp -f $(TARGET) /usr/local/bin

clean:
	rm -f $(OBJECTS)
