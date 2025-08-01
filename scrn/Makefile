CC = gcc
OBJDIR = ../build/scrn
TARGET = ../build/scrn.dll
SRC = $(wildcard src/*.c)

OBJ = $(patsubst src/%.c,$(OBJDIR)/src/%.o,$(SRC))

CFLAGS = -fPIC -Wall -Wextra -Iinclude -DSCRN_EXPORTS

.PHONY: all clean

all: $(TARGET)

$(OBJDIR)/src/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	mkdir -p $(dir $@)
	$(CC) -shared -o $@ $^

clean:
	rm -rf $(OBJDIR)
