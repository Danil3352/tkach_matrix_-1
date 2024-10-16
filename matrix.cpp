#include <iostream>
#include "matrix.hpp"
 
void input(int** matrix, size_t m, size_t n)
{
  for(size_t i=0; i<m; ++i)
  {
    for(size_t j=0; j<n; ++j)
    {
      std::cin >> matrix[i][j];
    }
  }
}

void output(const int * const * matrix, size_t m, size_t n)
{
  for(size_t i=0; i<m; ++i)
  {
    std::cout << matrix[i][0];
    for(size_t j=1; j<n; ++j)
    {
      std::cout << " " << matrix[i][j];
    }
    std::cout << "\n";
  }
}

void deletemtx(int** matrix, size_t m)
{
  for(size_t i=0; i<m; ++i) 
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

int** createmtx(size_t m, size_t n) 
{
  int** mtxptr = new int*[m];
  size_t created=0;
  try 
  {
    for(; created<m; ++created)
    {
      mtxptr[created] = new int[n];
    }
  }
  catch (const std::bad_alloc & e)
  {
    deletemtx(mtxptr,created);
    throw;
  }
  return mtxptr;
}
