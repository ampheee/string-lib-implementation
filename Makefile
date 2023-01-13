CC=gcc
CFLAGS=-Wall	-Wextra	-Werror	-std=c11
COVFLAGS=-fprofile-arcs	-ftest-coverage

OS=$(shell uname)
ifeq ($(OS), Darwin)
	PKGFLAGS=-lcheck
else
	CHECKFLAGS=-lcheck	-lpthread	-lpthread	-lrt	-lm	-lsubunit
endif	

all: clean test

test: string.a
	checkmk clean_mode=1 my.check > string_test.c
	$(CC)	$(CFLAGS)	string_test.c	lib_string.a	$(PKGFLAGS)	-o	test $(CHECKFLAGS)

string.a: clean
	$(CC)	$(CFLAGS)	-c	lib_string.c
	ar -rcs	lib_string.a	lib_string.o

clean:
	rm -rf *.a *.o report/ test *.out *.gcda *.gcno *.dSYM gcov_* *.*.gch string_test.*
	chmod -x *
	chmod +x string-lib-implementation

check:
	@echo

gcov_report:
#В цели gcov_report должен формироваться отчёт gcov в виде html страницы. Для этого unit-тесты должны запускаться с флагами gcov
