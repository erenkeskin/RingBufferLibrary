CC			= gcc
FLAGS		= -l./-O3 -Wall -c
CFILES		= $(shell ls | grep .c)
OFILES		= $(shell ls | grep .o)
EXEFILES	= $(shell ls | grep .exe)
OBJS		= $(CFILES: %.c = %.o)
RM			= rm -rf

all: $(OBJS)
	$(CC) $(OBJS) -o main

clear: 
	$(RM) $(OFILES) $(EXEFILES)