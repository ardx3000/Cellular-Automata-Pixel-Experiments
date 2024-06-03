#!/bin/bash

# Directories
SRC_DIR=src
INCLUDE_DIR=include

# Output executable
OUTPUT=CAAp

# Compiler and flags
CC=gcc
CFLAGS="-I${INCLUDE_DIR} -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL"

# Find all .c files in the src directory
SRC_FILES=$(find ${SRC_DIR} -name '*.c')

# Compile the project
${CC} -o ${OUTPUT} ${SRC_FILES} ${CFLAGS}
