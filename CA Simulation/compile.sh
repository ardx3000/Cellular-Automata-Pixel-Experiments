#!/bin/bash

# Compile all .c files in the current directory
gcc -o CAAp main.c -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
