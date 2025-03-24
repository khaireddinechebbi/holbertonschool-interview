#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

#define SLIDE_LEFT 0   // Define the macro for sliding left
#define SLIDE_RIGHT 1  // Define the macro for sliding right

int slide_line(int *line, size_t size, int direction);

#endif