CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++17

all: rayTracer

rayTracer : ray.o shape.o camera.o vectormath.o main.o
	$(CC) -o $@ $(CFLAGS) ray.o shape.o camera.o vectormath.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f rayTracer
