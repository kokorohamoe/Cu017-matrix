//Cu017_matrix
#include <iostream>
#include <thread>
#include <vector>

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
    std::vector<std::thread> mt(4);
/*
    mt[0]=std::thread(kernel,0,0);
    mt[1]=std::thread(kernel,0,1);
    mt[2]=std::thread(kernel,1,0);
    mt[3]=std::thread(kernel,1,1);
*/
    for(std::thread &t:mt) {
        int i = &t - &mt[0];
        mt[i]=std::thread(kernel,i/2,i%2);
        
    }
    for(std::thread &t:mt) t.join();
    std::cout << R[0][0] <<" " <<R[0][1]<<std::endl;
    std::cout << R[1][0] <<" " <<R[1][1]<<std::endl;
  return 0;
}