//Cu017_matrix
#include <iostream>
#include <thread>

const int N = 2;
void kernel(int *matrix_r,int *matrix_A,int *matrix_B,int y,int x);
{
  int *A[2][2] = (int *[2][2])matrix_A;
  int *B[2][2] = (int *[2][2])matrix_B;
  int *R[2][2] = (int *[2][2])matrix_r;
  
  R[y][x]=A[][]*B[][]+A[][]*B[][];
  
}  


int main(int argc,char *argv)
{
  return 0;
}