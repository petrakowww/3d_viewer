CPP = g++

FLAGS = -Wall -Werror -Wextra -Wpedantic -fprofile-arcs -ftest-coverage
STD_CPP = -std=c++17

FLAGS_TEST_CPP = -lgtest -pthread -fprofile-arcs -ftest-coverage -lstdc++ -lm

GCFLAGS = --coverage

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
DESKTOP_DIR = $(BUILD_DIR)/desktop
TEST_DIR = test_executable
INSTALL_DIR = /home/user/3DVIEWER
DESKTOP_EXEC_GAME = 3dviewer_desktop
ARCHIVE_DIR = dist

ARCHIVE_DIST_DIRS = gif controller model view tests

ARCHIVE_NAME = s21_3DViewer.tar.gz
DESTINATION_PROGRAM = 3dviewer_app
NAME_APP = 3DViewer
DVI_RESULT_DIR = dvi/result
TEST_EXECUTABLE = $(TEST_DIR)/s21_test_viewer

MAIN = s21_3d_viewer.cpp

SRC_DIRS = model tests
SRCS = $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

INCLUDE_HEADER_DIRS = $(shell find $(SRC_DIRS) -type f -name '*.h' -exec dirname {} \; | sort -u)

INCLUDES = $(foreach dir, $(INCLUDE_HEADER_DIRS), -I$(dir))

all: clean desktop test

desktop:
	mkdir -p $(DESTINATION_PROGRAM)
	mkdir -p $(BUILD_DIR) $(DESKTOP_DIR)
	cd $(DESKTOP_DIR) && qmake ../../view && make

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(FLAGS) $(STD_CPP) $(INCLUDES) -c $< -o $@

install: desktop
	@echo "┏=========================================┓"
	@echo "┃           Начинается установка          ┃"
	@echo "┗=========================================┛"
	sudo mkdir -p $(INSTALL_DIR)
	sudo cp ./$(DESTINATION_PROGRAM)/$(NAME_APP) $(INSTALL_DIR)
	@echo "┏=========================================┓"
	@echo "┃      Установка успешно завершена.       ┃"
	@echo "┃Используйте для удаления 'make uninstall'┃"
	@echo "┗=========================================┛"

uninstall:
	@echo "┏=========================================┓"
	@echo "┃           Начинается удаление           ┃"
	@echo "┗=========================================┛"
	sudo rm -rf $(INSTALL_DIR)
	@echo "┏=========================================┓"
	@echo "┃      Игра была успешно удалена.         ┃"
	@echo "┃ Используйте для установки 'make install'┃"
	@echo "┗=========================================┛"

dist: clean
	mkdir -p $(ARCHIVE_DIR)
	cp -r $(ARCHIVE_DIST_DIRS) $(ARCHIVE_DIR)/
	cp Makefile .clang-format $(MAIN) $(ARCHIVE_DIR)/
	tar -czvf $(ARCHIVE_NAME) -C $(ARCHIVE_DIR) .
	rm -rf $(ARCHIVE_DIR)
	@echo "Создан архив: $(ARCHIVE_NAME)"

$(TEST_EXECUTABLE): $(OBJS)
	mkdir -p $(TEST_DIR)
	$(CPP) $(FLAGS) $(STD_CPP) $(INCLUDES) $^ -o $@ $(FLAGS_TEST_CPP)

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

gcov_report: test
	lcov -t "gcov_report" -o coverage_html.info -c -d $(BUILD_DIR)
	# Исключаем внешние библиотеки
	lcov --remove coverage_html.info '/usr/*' '*/gtest/*' -o coverage_html.info --ignore-errors unused
	genhtml -o ./coverage_html coverage_html.info
	rm -rf *.info

dvi: clean_dvi
	doxygen dvi/Doxyfile

clean: clean_program clean_build clean_dvi clean_gcov clean_dist

clean_program:
	rm -rf $(DESTINATION_PROGRAM)

clean_dvi:
	rm -rf $(DVI_RESULT_DIR)

clean_build:
	rm -rf $(BUILD_DIR)
	rm -rf $(TEST_DIR)

clean_gcov:
	rm -rf ./coverage_html ./*.info

clean_dist:
	rm -rf ./*.gz

clang_format:
	@echo "Применение clang-format к коду..."
	@find . -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" \) -exec clang-format -style=file:.clang-format -i {} +
	@echo "Код отформатирован с использованием файла в формате .clang."

clang_check:
	@echo "Проверка форматирования кода с помощью clang-format..."
	@find . -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" \) -exec clang-format -style=file:.clang-format -n {} +
	@echo "Проверка форматирования кода завершена. Никаких изменений внесено не было."

.PHONY: all clean clean_program clean_dvi clean_build desktop test report dvi gcov_report clang_format clang_check install uninstall
