BINARY   := main.exe 
SOURCE   := ./src
INCLUDE  := ./include/
BUILDDIR := ./build
HEADERS := /mingw64/include

CC       ?= gcc
OPT      := O0

CFLAGS := $(foreach D, $(HEADERS), -I$(D))
CFLAGS += $(foreach D, $(INCLUDE), -I$(D))
CFLAGS += -Wall -Wextra -O0 -g

CFILES   := $(foreach D, $(SOURCE), $(wildcard $(D)/*.c))
OBJECTS  := $(patsubst %.c, $(BUILDDIR)/%.o, $(notdir $(CFILES)))

LIBS += -lm


all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $^ -o $@ $(LIBS)

$(BUILDDIR)/%.o: $(SOURCE)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

plot_delta:
	gnuplot ./gp_scripts/delta.gp

plot_harmonic:
	gnuplot ./gp_scripts/harmonic.gp
