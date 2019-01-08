CC=gcc
CFLAGS=-Wall -g

TARGET1=list
TARGET2=reverse
TARGET3=recRev

all: clean $(TARGET1) $(TARGET2) $(TARGET3)
$(TARGET1): $(TARGET1).c 
	$(CC) -o $(TARGET1) $(CFLAGS) $(TARGET1).c

$(TARGET2): $(TARGET2).c
	$(CC) -o $(TARGET2) $(CFLAGS) $(TARGET2).c

$(TARGET3): $(TARGET3).c
	$(CC) -o $(TARGET3) $(CFLAGS) $(TARGET3).c
clean:
	rm -f $(TARGET1).o $(TARGET2).o $(TARGET3).o 
	rm -f $(TARGET1) $(TARGET2) $(TARGET3)

