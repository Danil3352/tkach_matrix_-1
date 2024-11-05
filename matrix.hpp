#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

void outputMtx(std::ostream & out, const int * const * matrix, size_t m, size_t n);
int** createMtx(size_t n, size_t m);
void inputMtx(std::istream & in, int** matrix, size_t m, size_t n);
void deleteMtx(int** matrix, size_t m);

#endif
