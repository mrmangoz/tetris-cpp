CC = g++

ODIR = src/obj
HDIR = include
SRCDIR = src
CCFLAGS = $(HDIR) -Wall -g -pthread

OBJECTFILES = main.o grid.o inputthread.o tetromino.o
OBJS = $(patsubst %,$(ODIR)/%,$(OBJECTFILES))

HFILES = grid.hpp inputthread.hpp tetromino.hpp
DEPS = $(patsubst %,$(HDIR)/%,$(HFILES))


$(ODIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< -I $(CCFLAGS)

default: $(OBJS)
	$(CC) -o runnable $^ -I $(CCFLAGS)
	./runnable

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o