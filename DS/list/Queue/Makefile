CC=gcc
CFLAGS=-Wall -g

TARGET=queue

all: clean $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) -o $(TARGET) $(TARGET).c

clean:
	rm -f queue
