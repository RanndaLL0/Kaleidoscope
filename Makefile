CC = clang

CFLAGS = -Wall -Wextra -g -I. -Ilexer -Iparser -Itoken -Iutils

TARGET = kaleidoscope

SRCS = $(wildcard *.c) $(wildcard lexer/*.c) $(wildcard parser/*.c) $(wildcard utils/*.c) $(wildcard main_program/*.c)

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Build concluído! Execute com ./$(TARGET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Arquivos compilados foram removidos."

.PHONY: all clean
