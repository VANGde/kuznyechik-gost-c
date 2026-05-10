CC = gcc
CFLAGS = -Wall -Wextra -O3 -march=native
LDFLAGS =

TARGET = kuznechik_test
SRCS = main.c kuznyechik.c
OBJS = $(SRCS:.c=.o)
HEADERS = kuznyechik.h types.h

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
