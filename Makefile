all: test

CFLAG= -g -Wall -Wextra -Wpedantic -Wconversion

INCLUDES= src/*.h

COMMON_DEPS= $(INCLUDES) Makefile

test:
