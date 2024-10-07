CC = gcc
TARGET = temp
all: $(TARGET)
$(TARGET): temp.o
	$(CC) $(CFLAGS) -o $(TARGET) temp.o
temp.o: temp.c
	$(CC) $(CFLAGS) -c temp.c
clean:
	rm -f $(TARGET) *.o

