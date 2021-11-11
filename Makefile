HEADERS       := notakto.h
IMPLEMS       := notakto.cpp
OUT           := notakto
TEST          := notakto_test.cpp
TEST_OUT      := notakto_test
DRIVER        := main.cpp

FILES         := $(IMPLEMS) $(HEADERS) $(TEST) $(DRIVER)
OUTS          := $(OUT) $(TEST_OUT)
GTEST         := googletest
FLAGS         := -Wall -Werror -Wno-unused-function
TEST_FLAGS    := -Wall -Wno-unused-function -Wno-sign-compare -Wno-unused-variable -pthread 

.PHONY: format build test all clean

all: format build test

format:
	@echo "\n========================\nFormatting files\n========================\n"
	@clang-format $(FILES) -i -style=google -verbose
	@echo "\n========================\nFormatting complete\n========================\n"

build: $(DRIVER) $(IMPLEMS) $(HEADERS)
	@echo "\n========================\nCompiling program\n========================\n"
	@g++ -std=c++17 $(DRIVER) $(IMPLEMS) $(FLAGS) -o $(OUT)
	@echo "========================\nCompilation complete\nRun your code with ./$(OUT)\n========================\n"

test: $(TEST) $(IMPLEMS) $(HEADERS)
	@echo "\n========================\nRunning tests\n========================\n"
	@g++ -std=c++17 $(TEST) $(IMPLEMS) $(GTEST)/libgtest.a $(GTEST)/libgtest_main.a -isystem $(GTEST)/include $(TEST_FLAGS) -o $(TEST_OUT)
	@./$(TEST_OUT)
	@echo "\n========================\nTests complete\n========================\n"

clean:
	@rm -f $(OUTS)