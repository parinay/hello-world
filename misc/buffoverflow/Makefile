CC=gcc
CFLAGS=-Wall -g  -fno-stack-protector -m32 -no-pie
OBJD=objdump

TARGET=vuln

all: clean $(TARGET) $(TARGET).o

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

$(TARGET).o :
	$(OBJD) -d $(TARGET) > $(TARGET).o
clean:
	rm -f vuln
