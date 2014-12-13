
##############################
### VARIABLES
##############################

DEPS_DIR ?= ./deps

CPPFLAGS += -I$(DEPS_DIR)

CFLAGS ?= -std=c11 -g -Og \
          -Wall -Wextra -Wpedantic \
          -Wcomments -Wformat=2 -Wjump-misses-init -Wlogical-op \
          -Wmissing-include-dirs -Wnested-externs \
          -Wold-style-definition -Wredundant-decls -Wshadow \
          -Wstrict-prototypes -Wunused-macros -Wvla -Wwrite-strings \
          -Wno-override-init -Wno-unused-parameter

SLICE_LIMIT ?= 128

sources := $(wildcard *.c)
objects := $(sources:.c=.o)
mkdeps  := $(objects:.o=.dep.mk)

test_sources  := $(wildcard tests/*.c)
test_objects  := $(test_sources:.c=.o)
test_binaries := $(basename $(test_sources))


##############################
### BUILDING
##############################

.PHONY: all
all: slice.h objects tests

slice.h: slice-template.h
	$(DEPS_DIR)/libpp/templates/render.py $(SLICE_LIMIT) $< > $@

.PHONY: objects
objects: $(objects)

.PHONY: tests
tests: $(test_binaries)
tests/alloc: alloc.o
tests/require: require.o

.PHONY: test
test: tests
	./tests/run.bash 2>/dev/null

.PHONY: clean
clean:
	rm -rf $(objects) $(test_objects) $(test_binaries) $(mkdeps)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MF "$(@:.o=.dep.mk)" -c $< -o $@

-include $(mkdeps)

