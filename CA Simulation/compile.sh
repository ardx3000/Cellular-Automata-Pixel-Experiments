#!/bin/bash

# Compile all .c files in the current directory
gcc -o OpenGLExample *.c \
    -I/opt/homebrew/Cellar/glew/2.2.0_1/include \
    -I/opt/homebrew/Cellar/glfw/3.4/include \
    -L/opt/homebrew/Cellar/glew/2.2.0_1/lib \
    -lGLEW \
    -L/opt/homebrew/Cellar/glfw/3.4/lib \
    -lglfw \
    -framework OpenGL
