
##############################
### VARIABLES
##############################

DEPS_DIR ?= ./deps

CPPFLAGS += -I$(DEPS_DIR)

cflags_std := -std=c11
cflags_warnings := -Wall -Wextra -pedantic \
                   -Wcomments -Wformat=2 -Wjump-misses-init -Wlogical-op \
                   -Wmissing-include-dirs -Wnested-externs \
                   -Wold-style-definition -Wredundant-decls -Wshadow \
                   -Wstrict-prototypes -Wunused-macros -Wvla -Wwrite-strings \
                   -Wno-override-init -Wno-type-limits -Wno-unused-parameter

CFLAGS ?= $(cflags_std) -g $(cflags_warnings)

PYTHON ?= python

SLICE_LIMIT ?= 128

sources := $(wildcard *.c)
objects := $(sources:.c=.o)

test_sources  := $(wildcard tests/*.c)
test_objects  := $(test_sources:.c=.o)
test_binaries := $(test_sources:.c=)

mkdeps := $(objects:.o=.dep.mk) $(test_objects:.o=.dep.mk)


##############################
### BUILDING
##############################

.PHONY: all
all: objects tests

.PHONY: fast
fast: CPPFLAGS += -DNDEBUG
fast: CFLAGS = $(cflags_std) -O3 $(cflags_warnings)
fast: all

.PHONY: objects
objects: $(objects)

.PHONY: tests
tests: $(test_binaries)

.PHONY: test
test: tests
	./tests/run.bash 2>/dev/null

.PHONY: clean
clean:
	rm -rf slice.h $(objects) $(test_objects) $(test_binaries) $(mkdeps)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MF "$(@:.o=.dep.mk)" -c $< -o $@

slice.h: slice-template.h
	$(PYTHON) $(DEPS_DIR)/libpp/templates/render.py $(SLICE_LIMIT) $< -o $@

# So that the Make dependencies files are generated:
$(test_binaries): %: %.o

tests/slice.o: | slice.h
tests/alloc: alloc.o
tests/require: require.o

-include $(mkdeps)

