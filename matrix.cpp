#include <iostream>
#include "matrix.hpp"
#include "mtx_class.h"
 
void inputMtx(std::istream & in, int** matrix, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    for(size_t j = 0; j < n; ++j)
    {
      std::cin >> matrix[i][j];
    }
  }
}

void outputMtx(std::ostream & out, const int * const * matrix, size_t m, size_t n)
{
  for (size_t i = 0; i < m; ++i)
  {
    std::cout << matrix[i][0];
    for (size_t j = 1; j < n; ++j)
    {
      std::cout << " " << matrix[i][j];
    }
    std::cout << "\n";
  }
}

void deleteMtx(int** matrix, size_t m)
{
  for (size_t i = 0; i < m; ++i) 
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

int** createMtx(size_t m, size_t n) 
{
  int** mtxptr = new int*[m];
  size_t created = 0;
  try 
  {
    for (; created < m; ++created)
    {
      mtxptr[created] = new int[n];
    }
  }
  catch (const std::bad_alloc & e)
  {
    deleteMtx(mtxptr, created);
    throw;
  }
  return mtxptr;
}

void Matrix::getNumberOfRows(std::ostream & out) const
{
  std::cout << m_;
}

void Matrix::getNumberOfColumns(std::ostream & out) const
{
  std::cout << n_;
}

void Matrix::fillWithValue(const int value)
{
  for (size_t i = 0; i < m_; ++i)
  {
    for (size_t j = 0; j < n_; ++j)
    {
      matrix_[i][j] = value;
    }
  }
}

void Matrix::inputMethod(std::istream & in)
{
  ::inputMtx(in, matrix_, m_, n_);
}

void Matrix::outputMethod(std::ostream & out) const
{
  ::outputMtx(out, matrix_, m_, n_);
}

void Matrix::resizeMtx(const size_t newRowNum, const size_t newColumnNum)
{
  int** newSizeMtx = createMtx(newRowNum, newColumnNum);
  for (size_t i = 0; i < newRowNum; ++i)
  {
   for (size_t j = 0; j < newColumnNum; ++j)
   {
     newSizeMtx[i][j] = 0;
   }
  }
  for (size_t i = 0; i < m_ && i < newRowNum; ++i)
  {
   for (size_t j = 0; j < n_ && j < newColumnNum; ++j)
   {
     newSizeMtx[i][j] = matrix_[i][j];
   }
  }
  matrix_ = newSizeMtx;
  m_ = newRowNum;
  n_ = newColumnNum;
}