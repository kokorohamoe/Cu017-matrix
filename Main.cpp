//Cu017_matrix
#include <iostream>
#include <thread>

int R[2][2];
int A[2][2]={{1,2},{3,4}};
int B[2][2]={{5,6},{7,8}};

const int N = 2;
void kernel(int y,int x)
{

  R[y][x]=A[y][0]*B[0][x]+A[y][1]*B[1][x];
  
}  


int main(int argc,char *argv[])
{
    
    std::thread a00=std::thread(kernel,0,0);
    std::thread a01=std::thread(kernel,0,1);
    std::thread a10=std::thread(kernel,1,0);
    std::thread a11=std::thread(kernel,1,1);
    a00.join();
    a01.join();
    a10.join();
    a11.join();
    std::cout << R[0][0] <<" " <<R[0][1]<<std::endl;
    std::cout << R[1][0] <<" " <<R[1][1]<<std::endl;
  return 0;
}