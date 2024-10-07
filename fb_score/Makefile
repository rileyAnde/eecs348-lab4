CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = fb
all: $(TARGET)
$(TARGET): fb.o
	$(CC) $(CFLAGS) -o $(TARGET) fb.o

football_score.o: football_score.c
	$(CC) $(CFLAGS) -c fb.c
clean:
	rm -f $(TARGET) *.o
