#ifndef MTX_CLASS_H
#define MTX_CLASS_H

#include "matrix.hpp"

class Matrix 
{
public:
  Matrix(size_t m, size_t n): 
    m_(m),
    n_(n),
    matrix_(::createMtx(m_, n_))
  {}
  Matrix(const Matrix & mtx):
    m_(mtx.m_),
    n_(mtx.n_)
  {
    matrix_ = createMtx(m_, n_);
    for (size_t i = 0; i < m_; ++i)
    {
      for (size_t j = 0; j < n_; ++j)
      {
        matrix_[i][j] == mtx.matrix_[i][j];
      }
    }
  }
  void getNumberOfRows(std::ostream & out) const;
  void getNumberOfColumns(std::ostream & out) const;
  void fillWithValue(int value);
  void inputMethod(std::istream & in);
  void outputMethod(std::ostream & out) const;
  void resizeMtx(size_t newRowNum, size_t newColumnNum);
  ~Matrix()
  {
    ::deleteMtx(matrix_, m_);
  }
public:
  size_t m_ = 0, n_ = 0;
  int ** matrix_ = nullptr;
};

#endif