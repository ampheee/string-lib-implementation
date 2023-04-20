CC=gcc
# CFLAGS=-Wall	-Wextra	-Werror	-std=c11
COVFLAGS=-fprofile-arcs	-ftest-coverage

OS=$(shell uname)
ifeq ($(OS), Darwin)
	PKGFLAGS=-lcheck
else
	CHECKFLAGS=-lcheck	-lpthread	-lpthread	-lrt	-lm	-lsubunit
endif

all: clean lib_string.a

test:
	checkmk clean_mode=1 my.check > lib_string_test.c
	$(CC)	lib_string_test.c	lib_string.c	lib_sscanf.c	lib_sprintf.c	$(PKGFLAGS)	-o	lib_string_test $(CHECKFLAGS)	--coverage

lib_string.a: clean
	$(CC)	$(CFLAGS)	-c	lib_string.c lib_sprintf.c lib_sscanf.c
	ar rc	lib_string.a	*.o
	ranlib lib_string.a

gcov_report:	clean	lib_string.a test
	./lib_string_test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	rm -rf	*.gcno	*.gcda gcov_rep gcov_rep.* coverage.info
	chmod -x *.* Makefile
	open gcov_report/index.html

clean:
	rm -rf *.a *.o report/ lib_string_test *.out *.gcda *.gcno *.dSYM gcov_* *.*.gch lib_string_test.c	coverage.info

clean_test_temps:
	rm -rf lib_string_test*.* core*	

checkStyle:
	@echo //////////////START TEST////////////////
	cppcheck	*.c
	@echo cheeeck
