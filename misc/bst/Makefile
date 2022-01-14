TARGET = test_main
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

SOURCEDIR = src
BUILDDIR = build

.PHONY: all

all: $(BUILDDIR)/$(TARGET)

OBJECTS = $(wildcard $(SOURCEDIR)/*.c)
HEADERS = $(wildcard $(SOURCEDIR)/*.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(HEADERS) -Wall $(LIBS) -o $@

clean:
	-rm -f $(BUILDDIR)/$(TARGET)
