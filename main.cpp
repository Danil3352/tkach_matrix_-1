#include <iostream>
#include "matrix.hpp"
#include "mtx_class.h"

int main()
{
  size_t M = 0, N = 0;
  std::cin >> M >> N;
  if (!std::cin)
  {
    std::cerr << "Input error\n";
    return 1;
  }
  int** matrix = nullptr;
  try
  {
    matrix = createMtx(M, N);
  }
  catch(const std::bad_alloc & e)
  {
    deleteMtx(matrix, M);
    std::cerr << "Out of memory\n";
    return 1;
  }
  inputMtx(std::cin, matrix, M, N);
  if (!std::cin)
  {
    deleteMtx(matrix, M);
    std::cerr << "Input error\n";
    return 1;
  }
  outputMtx(std::cout, matrix, M, N);
  Matrix mtx(M, N);
  mtx.inputMethod(std::cin);
  try
  {
    mtx.resizeMtx(3, 4);
  }
  catch(const std::bad_alloc & e)
  {
    deleteMtx(matrix, M);
    std::cerr << "Out of memory\n";
    return 1;
  }
  mtx.outputMethod(std::cout);
  deleteMtx(matrix, M);
  return 0;
}
