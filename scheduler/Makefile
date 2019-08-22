###################################
# Sean Seever
# Meeting Scheduler
###################################
CC = g++                # use g++ for compiling c++ code or gcc for c code
CFLAGS = -g -Wall       # compilation flags: -g for debugging. Change to -O or -O\
2 for optimized code.
LIB = -lm     # linked libraries
LDFLAGS = -L.           # link flags
PROG = scheduler          # target executable (output)
OBJ = main.o room.o meeting.o person.o ac3.o  # object files for the target. Add more to this and next lines if there are more than o\
ne source files.
SRC = main.cpp room.cpp meeting.cpp person.cpp ac3.cpp       # .c or .cpp source files.

all :   $(PROG)

$(PROG):$(OBJ)
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)


# cleanup
clean:
	/bin/rm -f *.o $(PROG)
