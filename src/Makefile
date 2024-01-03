NAME = smart_calc.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SRCS = s21_smart_calc/*.c
TEST_SRCS = tests/*.c

# Используемые папки
SOURCE_DIR=s21_smart_calc
TSOURCES_DIR=tests
QT_DIR=qt
OBJ_DIR=build
INSTALL_DIR=bin
GCOV_DIR=gcov
DIST_DIR=SmartCalc_v1.0

EXECUTABLE:= /bin/bin

TEST_FLAGS = -lcheck -lm -lpthread
GCOV_FLAGS = -ftest-coverage -fprofile-arcs
UNAME_S = $(shell uname -s)

ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

all: clean_all test install

${NAME}:
	$(CC) $(CFLAGS) -c ${SRCS}
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm *.o

test: rebuild
	$(CC) $(CFLAGS) -c ${TEST_SRCS}
	$(CC) $(CFLAGS) *.o ${NAME} ${TEST_FLAGS}  -o test
	./test

gcov_report: 
	make clean
	$(CC) $(CFLAGS) -c ${TEST_SRCS}
	$(CC)  $(CFLAGS) $(GCOV_FLAGS) -c ${SRCS}
	$(CC)  $(CFLAGS) $(GCOV_FLAGS) *.o $(TEST_FLAGS) -o test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

install: 
	make clean
	rm -rf build
	mkdir build
	make ${NAME}
	cd s21_smart_calc && qmake ../s21_smart_calc/s21_smart_calc.pro && make && make clean && rm Makefile && cd ../ && mv s21_smart_calc/s21_smart_calc build
uninstall:
	rm -rf build

dvi: 
	open dvi.html

dist:
	rm -rf Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/
	mkdir Archive_SmartCalc_v1.0/src
	mkdir Archive_SmartCalc_v1.0/src/s21_smart_calc
	cp Makefile s21_smart_calc/*.c s21_smart_calc/*.h dvi.html Archive_SmartCalc_v1.0/src/
	cp s21_smart_calc/*.h s21_smart_calc/*.pro s21_smart_calc/*.cpp s21_smart_calc/*.ui s21_smart_calc/*.user Archive_SmartCalc_v1.0/src/s21_smart_calc/ 
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0/
	mv Archive_SmartCalc_v1.0.tgz $(HOME)/Desktop/
	rm -rf Archive_SmartCalc_v1.0/


rebuild: clean ${NAME}

clean:
	rm -rf test *.gcov *.css gcov*.html
	rm -rf *.o *.a *.out s21_smart_calc/.qmake.stash s21_smart_calc/*.user
	rm -rf *.gcda *.gcno *.info *.gch
	rm -rf test report

clean_all: 
	make clean
	rm -rf build

style: 
	clang-format --style=google ${SRCS}  ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.h ${TEST_SRCS} -n

correct_style: 
	clang-format --style=google ${SRCS} ${SOURCE_DIR}/*.cpp ${SOURCE_DIR}/*.h ${TEST_SRCS} -i

installqt:
	sudo apt update
	sudo apt install clang-format
	sudo apt install qtcreator -y
	sudo apt install qtbase5-dev qtwayland5-dev-tools qtwayland5 -y
	sudo apt install qt5-qmake -y