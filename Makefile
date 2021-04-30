CC = gcc

SRC_DIR 	= src
INCL_DIR 	= include
BUILD_DIR 	= build

FLAGS = -Wall -Werror

C_FILES = $(wildcard $(SRC_DIR)/*)
C_FILES += hw2.c

O_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(O_DIR)/%.o)

all: logger.so

logger.so: $(O_FILES)