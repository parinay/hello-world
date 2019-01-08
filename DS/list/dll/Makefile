CC=gcc
CFLAGS=-Wall -g

TARGET1=dll

all: clean $(TARGET1)
$(TARGET1): $(TARGET1).c 
	$(CC) -o $(TARGET1) $(CFLAGS) $(TARGET1).c

clean:
	rm -f $(TARGET1).o
	rm -f $(TARGET1)

