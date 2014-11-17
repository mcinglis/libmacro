
##############################
### VARIABLES
##############################

DEPS_ROOT ?= ./deps

CPPFLAGS += -I$(DEPS_ROOT)

cflags_std = -std=c11
cflags_warnings = -Wall -Wextra -Wpedantic \
		  -Wcomments -Wformat=2 -Wjump-misses-init -Wlogical-op \
		  -Wmissing-include-dirs -Wnested-externs \
		  -Wold-style-definition -Wredundant-decls -Wshadow \
		  -Wstrict-prototypes -Wunused-macros -Wvla -Wwrite-strings \
		  -Wno-override-init -Wno-unused-parameter
CFLAGS ?= $(cflags_std) -g -Og $(cflags_warnings)

sources = $(wildcard *.c)
objects = $(sources:.c=.o)

test_sources  = $(wildcard tests/*.c)
test_objects  = $(test_sources:.c=.o)
test_binaries = $(basename $(test_sources))

mkdeps = $(objects:.o=.dep.mk) $(test_objects:.o=.dep.mk)

$(shell mkdir -p .make)


##############################
### BUILDING
##############################

.PHONY: all
all: objects tests

.PHONY: fast
fast: CPPFLAGS += -DNDEBUG -DNO_ASSERT -DNO_REQUIRE -DNO_DEBUG
fast: CFLAGS = $(cflags_std) -O3 $(cflags_warnings)
fast: objects

.PHONY: objects
objects: $(objects)

.PHONY: tests
tests: $(test_binaries)
tests/alloc: alloc.o
tests/require: require.o

.PHONY: test
test: tests
	./tests/run.bash 2>/dev/null

%.o: %.c .make/deps
	$(CC) $(CFLAGS) $(CPPFLAGS) -MMD -MF "$(@:.o=.dep.mk)" -c $< -o $@

-include $(mkdeps)


##############################
### DEPENDENCIES
##############################

.PHONY: deps
deps: .make/deps
.make/deps: .make/libpp .make/libtypes
	@touch $@

.PHONY: libpp
libpp: .make/libpp
.make/libpp: dep_path    = libpp
.make/libpp: dep_origin  = https://github.com/mcinglis/libpp.git
.make/libpp: dep_version = v2.*
.make/libpp: .make/libpp-build
	@touch $@

.PHONY: libtypes
libtypes: .make/libtypes
.make/libtypes: dep_path    = libtypes
.make/libtypes: dep_origin  = https://github.com/mcinglis/libtypes.git
.make/libtypes: dep_version = v1.*
.make/libtypes: .make/libtypes-build
	@touch $@

.make/%-clone:
	if [ ! -d $(DEPS_ROOT)/$(dep_path) ]; then \
	    git clone $(dep_origin) $(DEPS_ROOT)/$(dep_path); \
	fi
	@touch $@

.make/%-update: .make/%-clone
	cd $(DEPS_ROOT)/$(dep_path) && \
	  git pull --tags origin master && \
	  t=$$(git tag --list "$(dep_version)" | tail -n 1) && \
	  if [ -z "$$t" ]; then \
	    echo "No tag with the specified pattern."; \
	    false; \
	  fi && \
	  git tag --verify "$$t" && \
	  git checkout "$$t"
	@touch $@

.make/%-build: .make/%-update
	DEPS_ROOT=$(DEPS_ROOT) \
	  $(MAKE) --directory="$(DEPS_ROOT)/$(dep_path)"
	@touch $@


##############################
### CLEANING
##############################

.PHONY: clean
clean:
	rm -rf $(mkdeps) $(objects) $(test_objects) $(test_binaries)

.PHONY: nuke
nuke: clean
	rm -rf .make $(DEPS_ROOT)


##############################
### META
##############################

# Don't delete any files resulting from nested wildcard rules.
.SECONDARY:


