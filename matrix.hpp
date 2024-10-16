#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

void output(const int * const * matrix, size_t m, size_t n);
int** createmtx(size_t m, size_t n);
void input(int** matrix, size_t m, size_t n);
void deletemtx(int** marix, size_t m);

#endif
