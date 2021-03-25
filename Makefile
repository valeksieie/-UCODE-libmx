IDIR = inc
ODIR = obj
SDIR = src
CC=clang
CFLAGS=-I $(IDIR)
CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -I $(IDIR)
NAME = libmx.a
DEPD = libmx.h
DEPS = $(patsubst %,$(IDIR)/%,$(DEPD))
SRCS := $(wildcard $(SDIR)/mx_*.c)

OBJT = $(SRCS:.c=.o)
OBJS = $(subst $(SDIR),$(ODIR),$(OBJT))

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	mkdir -p obj
	$(CC) -c -o $@ $< $(CCFLAGS)

$(NAME): $(OBJS)
	ar -rc $@ $^

.PHONY: clean uninstall reinstall

uninstall: clean
	rm -f $(NAME)
	
clean:
	rm -rf $(ODIR)
	rm -f *.a

reinstall: uninstall all
