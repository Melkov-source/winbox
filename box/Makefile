CC = gcc
OBJDIR = ../build/box
TARGET = ../build/box.exe

SRC = $(wildcard src/*.c) ../main.c

OBJ = $(patsubst src/%.c,$(OBJDIR)/src/%.o,$(patsubst ../%.c,$(OBJDIR)/%.o,$(SRC)))

CFLAGS = -Wall -Wextra -Iinclude -I../scrn/include

# Объектники scrn — теперь берем из ../build/scrn/src/*.o
SCRN_OBJS = $(wildcard ../build/scrn/src/*.o)

.PHONY: all clean

all: $(TARGET)

$(OBJDIR)/src/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: ../%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	mkdir -p $(dir $@)
	$(CC) -o $@ $^ $(SCRN_OBJS)

clean:
	rm -rf $(OBJDIR)
