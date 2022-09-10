# Written by Lasan Nishshanka
#
# 23 May 2022 & 04:50 P.M.

MAILC_EXE = Export/mailc

BEGIN:
	@echo "Please read makefile before use!"

ALL: BUILD TEST

BUILD:
	gcc -std=c99 -m64 -Wpedantic -Waggregate-return -Wall -Wcast-align -Wcast-qual -Wconversion -Wextra -Winit-self -Wpointer-arith -Wshadow -Wstrict-prototypes -Wswitch-default -Wswitch-enum -Wundef -Wuninitialized -Wunreachable-code -Wwrite-strings -g -O3 -o $(MAILC_EXE) Source/main.c

TEST:
	./$(MAILC_EXE)

DDD:
	ddd -args ./$(MAILC_EXE)

VALGRIND:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(MAILC_EXE)