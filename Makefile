CC = gcc

SO_FILE = logger.so

SRC_DIR 	= src
INCL_DIR 	= include
BUILD_DIR 	= build

FLAGS = -Wall -Werror -g

C_FILES = $(wildcard $(SRC_DIR)/*)

O_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
O_FILES += $(BUILD_DIR)/hw2.o

all: $(SO_FILE)

$(BUILD_DIR)/hw2.o: hw2.c
	@mkdir -p $(@D)
	gcc -c $(FLAGS) -I$(INCL_DIR) -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	gcc -c $(FLAGS) -I$(INCL_DIR) -o $@ $<


$(SO_FILE): $(O_FILES)
	gcc -shared -fPIC -o $@ $(O_FILES) -ldl

test: test/test.c
	gcc -o test/test $<

clean:
	rm -rf $(BUILD_DIR)
	rm $(SO_FILE)