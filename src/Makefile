NAME = smart_calc.a
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
SRCS = models/s21_calc_model.cc 
TEST_SRCS = tests/tests.cc
STYLE_SRCS = controllers/* models/* qt/*.cc qt/*.h tests/*.cc
# Используемые папки
SOURCE_DIR=s21_smart_calc
TSOURCES_DIR=tests
QT_DIR=qt
OBJ_DIR=build
INSTALL_DIR=bin
GCOV_DIR=gcov
DIST_DIR=SmartCalc_v1.0

EXECUTABLE:= /bin/bin

TEST_FLAGS =  -lgtest -lgtest_main -pthreads
GCOV_FLAGS = -ftest-coverage -fprofile-arcs

ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

all: clean_all test install

${NAME}:
	$(CXX) $(CXXFLAGS) -c ${SRCS}
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm *.o

test: rebuild
	$(CXX) $(CXXFLAGS) -c ${TEST_SRCS}
	$(CXX) $(CXXFLAGS) *.o ${NAME} ${TEST_FLAGS}  -o test
	./test

gcov_report: 
	make clean
	$(CXX) $(CXXFLAGS) -c ${TEST_SRCS}
	$(CXX)  $(CXXFLAGS) $(GCOV_FLAGS) -c ${SRCS}
	$(CXX)  $(CXXFLAGS) $(GCOV_FLAGS) *.o $(TEST_FLAGS) -o test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

install: 
	make clean
	rm -rf build
	mkdir build
	make ${NAME}
	cd qt && qmake ../qt/s21_smart_calc.pro && make && make clean && rm Makefile && cd ../ && mv qt/s21_smart_calc.app build
	open build/${SOURCE_DIR}.app/Contents/MacOS/s21_smart_calc
uninstall:
	rm -rf build

dvi: 
	open dvi.html

dist:
	rm -rf Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/src
	mkdir Archive_SmartCalc_v2.0/src/controllers/
	mkdir Archive_SmartCalc_v2.0/src/models/
	mkdir Archive_SmartCalc_v2.0/src/qt/
	mkdir Archive_SmartCalc_v2.0/src/tests/
	cp Makefile dvi.html Archive_SmartCalc_v2.0/src/
	cp controllers/*.cc controllers/*.h Archive_SmartCalc_v2.0/src/controllers/
	cp models/*.cc models/*.h Archive_SmartCalc_v2.0/src/models/
	cp qt/*.cc qt/*.h qt/*.pro qt/*.ui Archive_SmartCalc_v2.0/src/qt/
	cp tests/*.cc Archive_SmartCalc_v2.0/src/tests/
	tar cvzf Archive_SmartCalc_v2.0.tgz Archive_SmartCalc_v2.0/
	mv Archive_SmartCalc_v2.0.tgz $(HOME)/Desktop/
	rm -rf Archive_SmartCalc_v2.0/

rebuild: clean ${NAME}

clean:
	rm -rf test *.gcov *.css gcov*.html
	rm -rf *.o *.a *.out s21_smart_calc/.qmake.stash s21_smart_calc/*.user
	rm -rf *.gcda *.gcno *.info *.gch
	rm -rf test report
	rm -rf qt/s21_smart_calc.app qt/*.o qt/*.user qt/Makefile qt/moc* qt/.qmake.stash build/

clean_all: 
	make clean
	rm -rf build

style: 
	clang-format --style=google ${STYLE_SRCS} -n

correct_style: 
	clang-format --style=google ${STYLE_SRCS} -i

installqt:
	sudo apt update
	sudo apt install clang-format
	sudo apt install qtcreator -y
	sudo apt install qtbase5-dev qtwayland5-dev-tools qtwayland5 -y
	sudo apt install qt5-qmake -y
