#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "../include/tic_toc.h"

int main()
{
  Eigen::Matrix<int, 3, 3, Eigen::RowMajor> Arowmajor;
  Eigen::Matrix<int, 3, 3, Eigen::ColMajor> Acolmajor;

  Arowmajor << 8, 2, 2,
               9, 1, 4,
               3, 5, 4;
  Acolmajor << 8, 2, 2,
               9, 1, 4,
               3, 5, 4;
  std::cout << "cout input Arowmajor\n";
  std::cout << Arowmajor << std::endl;

  std::cout << "cout input Arowmajor\n";
  std::cout << Acolmajor << std::endl;

  std::cout << "In memory (rowumn-major):" << std::endl;
  for (int i = 0; i < Arowmajor.size(); i++)
    std::cout << *(Arowmajor.data() + i) << "  ";
  std::cout << std::endl << std::endl;

  std::cout << "In memory (column-major):" << std::endl;
  for (int i = 0; i < Acolmajor.size(); i++)
    std::cout << *(Acolmajor.data() + i) << "  ";
  std::cout << std::endl << std::endl;

  TicToc rowTime;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
        std::cout << Arowmajor(i,j) << " ";
  std::cout << "rowTime: " << rowTime.toc() << std::endl;

  TicToc colTime;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
        std::cout << Acolmajor(i,j) << " ";
  std::cout << "colTime: " << colTime.toc() << std::endl;
  return 0;
}