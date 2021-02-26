#ifndef SLIDE_LINE_H_
#define SLIDE_LINE_H_

#include <stdio.h>
#include <stdlib.h>

#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0

int slide_line(int *line, size_t size, int direction);
void slide_rigth(int *line, size_t size);
void slide_left(int *line, size_t size);

#endif
