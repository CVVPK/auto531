VPATH=src
IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)
MKDIR_P=mkdir -p

ODIR=src/obj
SDIR=script

_DEPS = date.h trainProg.h write.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = date.o main.o trainProg.o write.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(MKDIR_P) $(ODIR) $(SDIR)
	$(CC) -c -o $@ $< $(CFLAGS)

autoFTO: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~