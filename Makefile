# set the compiler
CC := gcc

# set the compiler flags
CFLAGS := -lSDL -lSDL_image -lSDL_ttf 

# add header files here
HDRS :=

# add source files here
SRCS :=gravite.c

# generate names of object files
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := prog

# default recipe
all: $(EXEC)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
