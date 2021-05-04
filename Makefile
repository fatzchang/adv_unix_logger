CC = gcc

SO_FILE = logger.so

SRC_DIR 	= src
INCL_DIR 	= include
BUILD_DIR 	= build

FLAGS = -Wall -Werror

C_FILES = $(wildcard $(SRC_DIR)/*)
C_FILES += hw2.c

O_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	gcc -c $(FLAGS) -I$(INCL_DIR) -o $@ $<

all: $(SO_FILE)

$(SO_FILE): $(O_FILES)
	gcc -shared -fPIC -o $@ $(O_FILES) -ldl

test: test.c
	gcc -o $@ $@.c

clean:
	rm -rf $(BUILD_DIR)
	rm $(SO_FILE)