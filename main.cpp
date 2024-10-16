#include <iostream>
#include "matrix.hpp"

int main()
{
  size_t M=0,N=0;
  std::cin >> M >> N;
  if (!std::cin)
  {
    std::cerr << "Input error\n";
    return 1;
  }
  int** matrix = nullptr;
  try
  {
    matrix = createmtx(M,N);
  }
  catch(const std::bad_alloc & e)
  {
    deletemtx(matrix,M);
    std::cerr << "Out of memory\n";
    return 1;
  }
  input(matrix,M,N);
  output(matrix,M,N);
  deletemtx(matrix,M);
  return 0;
}
