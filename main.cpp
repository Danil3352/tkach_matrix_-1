#include <iostream>
#include "matrix.hpp"
int main(){
  size_t M=0,N=0;
  std::cin >> M >> N;
  int **t = ct(M,N);
  input(t,M,N);
  output(t,M,N);
  delet(t,M,N);
  std::cout << M << " " << N << "\n";
}
